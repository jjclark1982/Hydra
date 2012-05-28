//
//  AppLoader.h
//
//  Created by Shazron Abdullah
//  Copyright 2011 Nitobi Software Inc.
//

#import <Foundation/Foundation.h>
#import "FileDownloadURLConnection.h"
#import "ZipOperation.h"

#ifdef CORDOVA_FRAMEWORK
    #import <Cordova/CDVPlugin.h>
#else
    #import "CDVPlugin.h"
#endif

@class StatusBarOverlayView;

@protocol StatusBarOverlayDelegate  
    
- (void) statusBarTapped:(NSUInteger)numberOfTaps;

@end


@interface AppLoader : CDVPlugin < FileDownloadURLConnectionDelegate, ZipOperationDelegate, StatusBarOverlayDelegate > {
}

@property (nonatomic, copy)	NSString* downloadsFolder;
@property (nonatomic, copy)	NSString* appsFolder;
@property (nonatomic, retain)	UINavigationBar* navigationBar;
@property (nonatomic, retain)	StatusBarOverlayView* overlayView;

- (void) load:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) fetch:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) remove:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;

@end


@interface StatusBarOverlayView : UIView {
    
}

@property (nonatomic, assign) id<StatusBarOverlayDelegate> delegate;

@end

/* Errors */

typedef enum 
{
    AppLoaderErrorAppNotFound = 1

} AppLoaderError;