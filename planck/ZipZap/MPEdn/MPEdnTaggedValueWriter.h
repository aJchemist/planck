/*
 *  MPEdn: An EDN (extensible data notation) I/O library for OS X and
 *  iOS. See https://github.com/scramjet/mpedn and
 *  https://github.com/edn-format/edn.
 *
 *  Copyright (c) 2013 Matthew Phillips <m@mattp.name>
 *
 *  The use and distribution terms for this software are covered by
 *  the Eclipse Public License 1.0
 *  (http://opensource.org/licenses/eclipse-1.0.php). By using this
 *  software in any fashion, you are agreeing to be bound by the terms
 *  of this license.
 *
 *  You must not remove this notice, or any other, from this software.
 */

#import <Foundation/Foundation.h>

@class MPEdnWriter;

/**
 * Protocol implemented by custom EDN tag writers.
 *
 * Custom writers can be registered using [MPEdnWriter addTagWriter:].
 */
@protocol MPEdnTaggedValueWriter<NSObject>

@required

/**
 * The name of the tag used to identify values handled by this writer
 * (not including the "#").
 */
- (NSString *) tagName;

/**
 * True if this writer can write the given value.
 */
- (BOOL) canWrite: (id) value;

/**
 * Write the given value to the writer using [MPEdnWriter outputObject:].
 */
- (void) writeValue: (id) value toWriter: (MPEdnWriter *) writer;

@end
