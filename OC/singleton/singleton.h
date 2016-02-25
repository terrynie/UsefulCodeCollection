//
//  singleton.h
//  This header file can be used to reduce the code that
//
//  Created by Terry on 2/24/16.
//  Copyright © 2016 Terry. All rights reserved.
//
//

/**
 Usage: import this header into class header
        use 
*/


//define the singleton interface
#define singletonInterface(name) +(instancetype)share##name;

#if __has_feature(objc_arc)
//use in ARC project
//define the singleton implementation
#define singletonImplementation(name) \
+ (instancetype)share##name { \
name *instance = [[[self class] alloc] init]; \
return instance; \
} \
static name *_instance = nil; \
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
    static dispatch_once_t onceToken; \
    dispatch_once(&onceToken, ^{ \
        _instance = [[super allocWithZone:zone] init]; \
    }); \
    return _instance; \
} \
- (id)copyWithZone:(NSZone *)zone { \
    return _instance; \
} \
- (id)mutableCopyWithZone:(NSZone *)zone { \
    return _instance; \
}

#else

//use in MRC project
//define the singleton implementation
#define singletonImplementation(name) \
+(instancetype)share##name { \
name *instance = [[self alloc] init]; \
return instance; \
} \
static name *_instance = nil; \
+ (instancetype)allocWithZone:(struct _NSZone *)zone { \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[super allocWithZone:zone] init]; \
}); \
return _instance; \
} \
- (id)copyWithZone:(NSZone *)zone { \
return _instance; \
} \
- (id)mutableCopyWithZone:(NSZone *)zone { \
return _instance; \
} \
- (instancetype)retain { \
return _instance; \
} \
-(oneway void)release { \
} \
-(NSUInteger)retainCount { \
    return MAXFLOAT; \
} 


#endif
