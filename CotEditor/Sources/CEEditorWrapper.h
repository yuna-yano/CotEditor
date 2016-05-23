/*
 
 CEEditorWrapper.h
 
 CotEditor
 http://coteditor.com
 
 Created by nakamuxu on 2004-12-08.
 
 ------------------------------------------------------------------------------
 
 © 2004-2007 nakamuxu
 © 2014-2016 1024jp
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 */

@import Cocoa;
#import "CETextView.h"


@class CETextView;
@class CETheme;
@class CESyntaxStyle;


@interface CEEditorWrapper : NSResponder

@property (nonatomic) BOOL showsLineNum;
@property (nonatomic) BOOL wrapsLines;
@property (nonatomic) BOOL showsPageGuide;
@property (nonatomic) BOOL showsInvisibles;
@property (nonatomic, getter=isVerticalLayoutOrientation) BOOL verticalLayoutOrientation;

@property (readonly, nonatomic, nullable) CETextView *focusedTextView;
@property (readonly, nonatomic) BOOL showsNavigationBar;
@property (readonly, nonatomic) BOOL canActivateShowInvisibles;


#pragma mark Public Methods

// text processing
- (nonnull NSString *)string;
- (nonnull NSString *)substringWithRange:(NSRange)range;
- (nonnull NSString *)substringWithSelection;

- (void)insertTextViewString:(nonnull NSString *)inString;
- (void)insertTextViewStringAfterSelection:(nonnull NSString *)string;
- (void)replaceTextViewAllStringWithString:(nonnull NSString *)string;
- (void)appendTextViewString:(nonnull NSString *)string;

- (NSRange)selectedRange;  // line ending applied
- (void)setSelectedRange:(NSRange)charRange;  // line ending applied

- (void)markupRanges:(nonnull NSArray<NSValue *> *)ranges;
- (void)clearAllMarkup;

- (BOOL)isAutoTabExpandEnabled;
- (void)setAutoTabExpandEnabled:(BOOL)autoTabExpandEnabled;

// navigation bar
- (void)setShowsNavigationBar:(BOOL)showsNavigationBar animate:(BOOL)performAnimation;

// font
- (nullable NSFont *)font;
- (BOOL)usesAntialias;

// theme
- (void)setThemeWithName:(nonnull NSString *)themeName;
- (nullable CETheme *)theme;

- (void)invalidateStyleInTextStorage;


#pragma mark Action Messages

- (IBAction)toggleLineNumber:(nullable id)sender;
- (IBAction)toggleNavigationBar:(nullable id)sender;
- (IBAction)toggleLineWrap:(nullable id)sender;
- (IBAction)toggleLayoutOrientation:(nullable id)sender;
- (IBAction)toggleAntialias:(nullable id)sender;
- (IBAction)toggleInvisibleChars:(nullable id)sender;
- (IBAction)togglePageGuide:(nullable id)sender;
- (IBAction)toggleAutoTabExpand:(nullable id)sender;
- (IBAction)changeTabWidth:(nullable id)sender;
- (IBAction)changeLineHeight:(nullable id)sender;

- (IBAction)selectPrevItemOfOutlineMenu:(nullable id)sender;
- (IBAction)selectNextItemOfOutlineMenu:(nullable id)sender;
- (IBAction)openSplitTextView:(nullable id)sender;
- (IBAction)closeSplitTextView:(nullable id)sender;
- (IBAction)changeTheme:(nullable id)sender;

@end




#pragma mark -

@interface CEEditorWrapper (SyntaxParsing)

@property (readonly, nonatomic, nullable) CESyntaxStyle *syntaxStyle;


- (IBAction)recolorAll:(nullable id)sender;

- (void)invalidateSyntaxHighlight;
- (void)invalidateOutlineMenu;

@end




#pragma mark -

typedef NS_ENUM(NSUInteger, CEGoToType) {
    CEGoToLine,
    CEGoToCharacter
};

@interface CEEditorWrapper (Locating)

- (NSRange)rangeWithLocation:(NSInteger)location length:(NSInteger)length;  // line ending applied
- (void)setSelectedCharacterRangeWithLocation:(NSInteger)location length:(NSInteger)length;  // line ending applied
- (void)setSelectedLineRangeWithLocation:(NSInteger)location length:(NSInteger)length;  // line ending applied
- (void)gotoLocation:(NSInteger)location length:(NSInteger)length type:(CEGoToType)type;  // line ending applied

@end
