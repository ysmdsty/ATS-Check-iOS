// Generated by Apple Swift version 2.2 (swiftlang-703.0.18.8 clang-703.0.31)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import UIKit;
@import QuartzCore;
@import Foundation;
@import ObjectiveC;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class UICollectionView;
@class NSIndexPath;
@class UICollectionReusableView;

SWIFT_PROTOCOL("_TtP4Bond32BNDCollectionViewProxyDataSource_")
@protocol BNDCollectionViewProxyDataSource
@optional
- (UICollectionReusableView * _Nonnull)collectionView:(UICollectionView * _Nonnull)collectionView viewForSupplementaryElementOfKind:(NSString * _Nonnull)kind atIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (BOOL)collectionView:(UICollectionView * _Nonnull)collectionView canMoveItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (void)collectionView:(UICollectionView * _Nonnull)collectionView moveItemAtIndexPath:(NSIndexPath * _Nonnull)sourceIndexPath toIndexPath:(NSIndexPath * _Nonnull)destinationIndexPath;

/// Override to specify reload or update
- (BOOL)shouldReloadInsteadOfUpdateCollectionView:(UICollectionView * _Nonnull)collectionView;
@end

@class UITableView;

SWIFT_PROTOCOL("_TtP4Bond27BNDTableViewProxyDataSource_")
@protocol BNDTableViewProxyDataSource
@optional
- (NSString * _Nullable)tableView:(UITableView * _Nonnull)tableView titleForHeaderInSection:(NSInteger)section;
- (NSString * _Nullable)tableView:(UITableView * _Nonnull)tableView titleForFooterInSection:(NSInteger)section;
- (BOOL)tableView:(UITableView * _Nonnull)tableView canEditRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (BOOL)tableView:(UITableView * _Nonnull)tableView canMoveRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (NSArray<NSString *> * _Nullable)sectionIndexTitlesForTableView:(UITableView * _Nonnull)tableView;
- (NSInteger)tableView:(UITableView * _Nonnull)tableView sectionForSectionIndexTitle:(NSString * _Nonnull)title atIndex:(NSInteger)index;
- (void)tableView:(UITableView * _Nonnull)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (void)tableView:(UITableView * _Nonnull)tableView moveRowAtIndexPath:(NSIndexPath * _Nonnull)sourceIndexPath toIndexPath:(NSIndexPath * _Nonnull)destinationIndexPath;

/// Override to specify reload or update
- (BOOL)shouldReloadInsteadOfUpdateTableView:(UITableView * _Nonnull)tableView;

/// Override to specify custom row animation when row is being inserted, deleted or updated
- (UITableViewRowAnimation)tableView:(UITableView * _Nonnull)tableView animationForRowAtIndexPaths:(NSArray<NSIndexPath *> * _Nonnull)indexPaths;

/// Override to specify custom row animation when section is being inserted, deleted or updated
- (UITableViewRowAnimation)tableView:(UITableView * _Nonnull)tableView animationForRowInSections:(NSSet<NSNumber *> * _Nonnull)sections;
@end


@interface CALayer (SWIFT_EXTENSION(Bond))
@end


@interface NSIndexSet (SWIFT_EXTENSION(Bond))
@end


@interface NSLayoutConstraint (SWIFT_EXTENSION(Bond))
@end


@interface NSLock (SWIFT_EXTENSION(Bond))
- (nonnull instancetype)initWithName:(NSString * _Nonnull)name;
@end


@interface NSNotificationCenter (SWIFT_EXTENSION(Bond))
@end


@interface NSObject (SWIFT_EXTENSION(Bond))
@end


@interface NSObject (SWIFT_EXTENSION(Bond))
@end


@interface NSRecursiveLock (SWIFT_EXTENSION(Bond))
- (nonnull instancetype)initWithName:(NSString * _Nonnull)name;
@end


@interface UIActivityIndicatorView (SWIFT_EXTENSION(Bond))
@end


@interface UIBarItem (SWIFT_EXTENSION(Bond))
@end


@interface UIButton (SWIFT_EXTENSION(Bond))
@end


@interface UICollectionView (SWIFT_EXTENSION(Bond))
@end


@interface UIControl (SWIFT_EXTENSION(Bond))
@end


@interface UIDatePicker (SWIFT_EXTENSION(Bond))
@end


@interface UIImageView (SWIFT_EXTENSION(Bond))
@end


@interface UILabel (SWIFT_EXTENSION(Bond))
@end


@interface UINavigationBar (SWIFT_EXTENSION(Bond))
@end


@interface UINavigationItem (SWIFT_EXTENSION(Bond))
@end


@interface UIProgressView (SWIFT_EXTENSION(Bond))
@end


@interface UIRefreshControl (SWIFT_EXTENSION(Bond))
@end


@interface UISegmentedControl (SWIFT_EXTENSION(Bond))
@end


@interface UISlider (SWIFT_EXTENSION(Bond))
@end


@interface UISwitch (SWIFT_EXTENSION(Bond))
@end


@interface UITableView (SWIFT_EXTENSION(Bond))
@end


@interface UITextField (SWIFT_EXTENSION(Bond))
@end


@interface UITextView (SWIFT_EXTENSION(Bond))
@end


@interface UIView (SWIFT_EXTENSION(Bond))
@end

#pragma clang diagnostic pop
