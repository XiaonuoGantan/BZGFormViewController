//
//  BZGTextFieldCell.h
//
//  https://github.com/benzguo/BZGFormViewController
//

#import <UIKit/UIKit.h>
#import "BZGInfoCell.h"

typedef NS_ENUM(NSInteger, BZGValidationState) {
    BZGValidationStateInvalid,
    BZGValidationStateWarning,
    BZGValidationStateValid,
    BZGValidationStateValidating,
    BZGValidationStateNone
};

@interface BZGTextFieldCell : UITableViewCell <UITextFieldDelegate>

@property (strong, nonatomic) UILabel *label;
@property (strong, nonatomic) UITextField *textField;

/// The color of the text field's text when the cell's state is not invalid.
@property (strong, nonatomic) UIColor *textFieldNormalColor;

/// The color of the text field's text when the cell's state is invalid.
@property (strong, nonatomic) UIColor *textFieldInvalidColor;

@property (strong, nonatomic) UIActivityIndicatorView *activityIndicatorView;

/// The current validation state. Default is BZGValidationStateNone.
@property (assign, nonatomic) BZGValidationState validationState;

/// The cell displayed when the cell's validation state is Invalid or Warning.
@property (strong, nonatomic) BZGInfoCell *infoCell;

/// A value indicating whether or not the cell shows a checkmark when valid. Default is YES.
@property (assign, nonatomic) BOOL showsCheckmarkWhenValid;

/// A value indicating whether or not the cell displays its validation state while being edited. Default is NO.
@property (assign, nonatomic) BOOL showsValidationWhileEditing;

/// The block called when the text field's text begins editing.
@property (copy, nonatomic) void (^didBeginEditingBlock)(BZGTextFieldCell *cell, NSString *text);

/**
 * The block called before the text field's text changes.
 * The block's newText parameter will be the text field's text after changing. Return NO if the text shouldn't change.
 */
@property (copy, nonatomic) BOOL (^shouldChangeTextBlock)(BZGTextFieldCell *cell, NSString *newText);

/// The block called when the text field's text ends editing.
@property (copy, nonatomic) void (^didEndEditingBlock)(BZGTextFieldCell *cell, NSString *text);

/// The block called before the text field returns. Return NO if the text field shouldn't return.
@property (copy, nonatomic) BOOL (^shouldReturnBlock)(BZGTextFieldCell *cell, NSString *text);

/**
 * Returns the parent BZGFormFieldCell for the given text field. If no cell is found, returns nil.
 *
 * @param textField A UITextField instance that may or may not belong to this BZGFormFieldCell instance.
 */
+ (BZGTextFieldCell *)parentCellForTextField:(UITextField *)textField;

@end
