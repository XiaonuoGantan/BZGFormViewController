//
//  BZGFormViewController.h
//
//  https://github.com/benzguo/BZGFormViewController
//

#import <UIKit/UIKit.h>

@class BZGTextFieldCell, BZGInfoCell;

@interface BZGFormViewController : UIViewController <UITableViewDelegate, UITableViewDataSource, UITextFieldDelegate>

/// The table view managed by the controller object.
@property (nonatomic, strong) UITableView *tableView;

/// The form cells used to populate the table view's form section.
@property (nonatomic, strong) NSMutableArray *formCells;

/// The table view section where the form should be displayed.
@property (nonatomic, assign) NSUInteger formSection;

/**
 * Initializes a form view controller to manage a table view of a given style.
 *
 * @param style A constant that specifies the style of table view that the controller object is to manage (UITableViewStylePlain or UITableViewStyleGrouped).
 * @return An initialized BZGFormViewController object or nil if the object couldn’t be created.
 */
- (id)initWithStyle:(UITableViewStyle)style;

/**
 * Updates the display state of the info cell below a form cell.
 *
 * @param cell an instance of BZGFormFieldCell in a BZGFormViewController's formFieldCells
 */
- (void)updateInfoCellBelowFormCell:(BZGTextFieldCell *)cell;

/**
 * Returns the next form cell.
 *
 * @param cell The starting form field cell.
 * @return The next form field cell or nil if no cell is found.
 */
- (BZGTextFieldCell *)nextFormCell:(BZGTextFieldCell *)cell;

/**
 * Returns the first invalid form field cell.
 *
 * @return The first form field cell with state 'BZGValidationStateInvalid' or nil if no cell is found.
 */
- (BZGTextFieldCell *)firstInvalidFormCell;


@end
