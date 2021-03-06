//
//  APIFetcher.h
//  OAuthDemo
//
//  Created by Jiao Liu on 15/6/3.
//  Copyright (c) 2015年 Xibo Wang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OAuth2Authentication.h"

@class OAuth2Authentication;
@interface APIFetcher : NSObject
@property (strong, nonatomic) OAuth2Authentication *auth;
@property (strong, nonatomic) NSString *accessToken;
@property (strong, nonatomic) NSString *refreshToken;

// init

+ (APIFetcher *)fetcherWithOAuth2:(OAuth2Authentication *)auth
                      accessToken:(NSString *)accessToken
                     refreshToken:(NSString *)refreshToken;


// fetch api

- (void)sendGetRequestToAPIPath:(NSString *)path onCompletion:(void (^)(NSData *data, NSError *error))handler;

- (void)refreshAccessToken;
// just for testing

- (void)getUserProfile;
- (void)getLastSyncTimeOnCompletion:(void (^)(BOOL needUpdate, NSError *error))handler;

@end
