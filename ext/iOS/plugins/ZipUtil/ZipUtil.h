//
//  ZipPlugin.m
//
//  Created by Shazron Abdullah
//  Copyright 2011 Nitobi Software Inc.
//


#import <Foundation/Foundation.h>
#import "ZipArchive.h"
#import "ZipOperation.h"

#ifdef CORDOVA_FRAMEWORK
    #import <Cordova/CDVPlugin.h>
#else
    #import "CDVPlugin.h"
#endif

@interface ZipUtil : CDVPlugin < ZipOperationDelegate > {

}

@property (nonatomic, retain) NSOperationQueue* operationQueue;

- (void) unzip:(ZipOperation*)zipOperation;
- (void) zip:(ZipOperation*)zipOperation;

- (void) unzip:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;
- (void) zip:(NSMutableArray*)arguments withDict:(NSMutableDictionary*)options;

@end
