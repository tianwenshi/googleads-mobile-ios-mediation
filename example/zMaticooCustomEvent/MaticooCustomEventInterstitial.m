#import "MaticooCustomEventInterstitial.h"
#include <stdatomic.h>
#include "MaticooMediationTrackManager.h"
@import MaticooSDK;
#import "MaticooCustomExtras.h"

@interface MaticooCustomEventInterstitial () <GADMediationAdapter, GADMediationInterstitialAd, MATInterstitialAdDelegate> {
  /// The completion handler to call when the ad loading succeeds or fails.
  GADMediationInterstitialLoadCompletionHandler _loadCompletionHandler;

  /// The ad event delegate to forward ad rendering events to the Google Mobile Ads SDK.
  id<GADMediationInterstitialAdEventDelegate> _adEventDelegate;
    
    MATInterstitialAd *_interstitial;
}

@end

@implementation MaticooCustomEventInterstitial

#pragma mark GADCustomEventInterstitial implementation


+ (void)setUpWithConfiguration:(GADMediationServerConfiguration *)configuration
             completionHandler:(GADMediationAdapterSetUpCompletionBlock)completionHandler {
  // This is where you you will initialize the SDK that this custom event is built for.
  // Upon finishing the SDK initialization, call the completion handler with success.
    NSString *appkey = [[NSBundle mainBundle].infoDictionary objectForKey:@"zMaticooAppKey"];
      if(appkey == nil && ![appkey isEqualToString:@""]){
          NSError *error= [NSError errorWithDomain:@"com.google.zmaticoo" code:100 userInfo:[NSDictionary dictionaryWithObject:@"zmaticoo appkey is null" forKey:@"reason"]];
          completionHandler(error);
      }else{
          [[MaticooAds shareSDK] initSDK:appkey onSuccess:^{
              completionHandler(nil);
              [MaticooMediationTrackManager trackMediationInitSuccess];
          } onError:^(NSError * _Nonnull error) {
              completionHandler(error);
              [MaticooMediationTrackManager trackMediationInitFailed:error];
          }];
      }
}

+ (GADVersionNumber)adSDKVersion {
  GADVersionNumber version = {1,3,4};
  return version;
}

+ (GADVersionNumber)adapterVersion {
  GADVersionNumber version = {1.1};
  return version;
}

+ (nullable Class<GADAdNetworkExtras>)networkExtrasClass {
    return [MaticooCustomExtras class];
}

- (void)loadInterstitialForAdConfiguration:
            (GADMediationInterstitialAdConfiguration *)adConfiguration
                         completionHandler:
                             (GADMediationInterstitialLoadCompletionHandler)completionHandler {
  __block atomic_flag completionHandlerCalled = ATOMIC_FLAG_INIT;
  __block GADMediationInterstitialLoadCompletionHandler originalCompletionHandler =
      [completionHandler copy];

  _loadCompletionHandler = ^id<GADMediationInterstitialAdEventDelegate>(
      _Nullable id<GADMediationInterstitialAd> ad, NSError *_Nullable error) {
    // Only allow completion handler to be called once.
    if (atomic_flag_test_and_set(&completionHandlerCalled)) {
      return nil;
    }

    id<GADMediationInterstitialAdEventDelegate> delegate = nil;
    if (originalCompletionHandler) {
      // Call original handler and hold on to its return value.
      delegate = originalCompletionHandler(ad, error);
    }

    // Release reference to handler. Objects retained by the handler will also be released.
    originalCompletionHandler = nil;

    return delegate;
  };
    NSString *adUnit = adConfiguration.credentials.settings[@"parameter"];
    if (adUnit == nil){
        NSError *error= [NSError errorWithDomain:@"com.google.zmaticoo" code:100 userInfo:[NSDictionary dictionaryWithObject:@"zmaticoo placement id is null" forKey:@"reason"]];
        _loadCompletionHandler(nil, error);
        return;
    }
    _interstitial = [[MATInterstitialAd alloc] initWithPlacementID:adUnit];
    _interstitial.delegate = self;
    id extras = adConfiguration.extras;
    if (extras != nil && [extras isKindOfClass:[MaticooCustomExtras class]]){
        _interstitial.localExtra = ((MaticooCustomExtras *)extras).localExtra;
    }
    [_interstitial loadAd];
    [MaticooMediationTrackManager trackMediationAdRequest:adUnit adType:INTERSTITIAL isAutoRefresh:NO];
}

#pragma mark GADMediationInterstitialAd implementation

- (void)presentFromViewController:(UIViewController *)viewController {
    if (_interstitial && _interstitial.isReady) {
        [_interstitial showAdFromViewController:viewController];
        [MaticooMediationTrackManager trackMediationAdShow:_interstitial.placementID adType:INTERSTITIAL];
    }
}


#pragma mark - Delegate

- (void)interstitialAdDidLoad:(MATInterstitialAd *)interstitialAd{
    _adEventDelegate = _loadCompletionHandler(self, nil);
    [MaticooMediationTrackManager trackMediationAdRequestFilled:interstitialAd.placementID adType:INTERSTITIAL];
}

- (void)interstitialAd:(MATInterstitialAd *)interstitialAd didFailWithError:(NSError *)error{
    _adEventDelegate = _loadCompletionHandler(nil, error);
    [MaticooMediationTrackManager trackMediationAdRequestFailed:interstitialAd.placementID adType:INTERSTITIAL msg:error.description];
}

- (void)interstitialAdWillLogImpression:(MATInterstitialAd *)interstitialAd{
    [_adEventDelegate willPresentFullScreenView];
    [_adEventDelegate reportImpression];
    [MaticooMediationTrackManager trackMediationAdImp:interstitialAd.placementID adType:INTERSTITIAL];
}

- (void)interstitialAdDidClick:(MATInterstitialAd *)interstitialAd{
    [_adEventDelegate reportClick];
    [MaticooMediationTrackManager trackMediationAdClick:interstitialAd.placementID adType:INTERSTITIAL];
}

//did click close button
- (void)interstitialAdDidClose:(MATInterstitialAd *)interstitialAd{
    [_adEventDelegate didDismissFullScreenView];
}

- (void)interstitialAd:(MATInterstitialAd *)interstitialAd displayFailWithError:(NSError *)error{
    [_adEventDelegate didFailToPresentWithError:error];
    [MaticooMediationTrackManager trackMediationAdImpFailed:interstitialAd.placementID adType:INTERSTITIAL msg:error.description];
}
@end
