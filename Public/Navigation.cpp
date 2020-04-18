/**
* AR Navigation
*
* Copyright 2020 Denis Esie
**/

#if PLATFORM_IOS
#import <Foundation/Foundation.h>
#include "NavigationBridge.h"
#endif

#include "NavigationPrivate.h"
#include "Navigation.h"

#define LOCTEXT_NAMESPACE "FNavigationModule"

void FNavigationModule::StartupModule()
{
    #if PLATFORM_IOS
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        [iOSPlatformProvider startup];
    });
    #endif
}

void FNavigationModule::ShutdownModule()
{
    #if PLATFORM_IOS
    [iOSPlatformProvider shutdown];
    #endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNavigationModule, Navigation)
