//
//  NSString+MIMEType.m
//  TNScrollView
//
//  Created by Terry on 4/13/16.
//  Copyright © 2016 Terry. All rights reserved.
//

#import "NSString+MIMEType.h"
#import <MobileCoreServices/MobileCoreServices.h>

@implementation NSString (MIMEType)
-(NSString *)MIMEType {
    if (![[NSFileManager defaultManager] fileExistsAtPath:self]) {
        return nil;
    }
    CFStringRef UTI = UTTypeCreatePreferredIdentifierForTag(kUTTagClassFilenameExtension, (__bridge CFStringRef)[self pathExtension], NULL);
    CFStringRef MIMEType = UTTypeCopyPreferredTagWithClass(UTI, kUTTagClassMIMEType);
    CFRelease(UTI);
    if (!MIMEType) {
        return @"application/octet-stream";
    }
    return (__bridge NSString *)MIMEType;
}

//-(NSString *)MIMETypeSynchronous {
//    NSURLResponse *response = nil;
//    NSURLRequest *request;
//    NSError *error;
//    if ([self hasPrefix:@"http://"] || [self hasPrefix:@"https://"]) {
//        request = [NSURLRequest requestWithURL:[NSURL URLWithString:self]];
////    }else if (self){
//        
//    }else {
//        request = [NSURLRequest requestWithURL:[NSURL fileURLWithPath:self]];
//    }
//    [NSURLConnection sendSynchronousRequest:request returningResponse:&response error:&error];
//    return response.MIMEType;
//}
@end
