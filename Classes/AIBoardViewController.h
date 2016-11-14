/***************************************************************************
 *  Copyright 2009-2010 Nevo Hua  <nevo.hua@playxiangqi.com>               *
 *                                                                         * 
 *  This file is part of NevoChess.                                        *
 *                                                                         *
 *  NevoChess is free software: you can redistribute it and/or modify      *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  NevoChess is distributed in the hope that it will be useful,           *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with NevoChess.  If not, see <http://www.gnu.org/licenses/>.     *
 ***************************************************************************/

#import <UIKit/UIKit.h>
#import "BoardViewController.h"
#import "CChessGame.h"
#import "AIRobot.h";

@interface AIBoardViewController : UIViewController
                            <BoardOwner, AIRobotDelegate, UIActionSheetDelegate>
{
    IBOutlet UIToolbar*               _toolbar;
    IBOutlet UIActivityIndicatorView* _activity;
    IBOutlet UIBarButtonItem*         _resetButton;
    IBOutlet UIBarButtonItem*         _actionButton;
    IBOutlet UIBarButtonItem*         _reverseRoleButton;
    IBOutlet UIBarButtonItem*         _suspendAIButton;

    UIBarButtonItem*      _resumeAIButton;
    BOOL                  _aiSuspended;

    BoardViewController*  _board;
    CChessGame*           _game;
    ColorEnum             _myColor;  // The color (role) of the LOCAL player.

    NSTimer*              _aiTimer;  // To schedule AI's Move-Generation.
    AIRobot*              _aiRobot;

    UIActivityIndicatorView* _aiThinkingActivity;
    UIBarButtonItem*         _aiThinkingButton;
}

@property (nonatomic, retain) NSTimer* _aiTimer;

- (IBAction)homePressed:(id)sender;
- (IBAction)resetPressed:(id)sender;
- (IBAction)actionPressed:(id)sender;
- (IBAction)reverseRolePressed:(id)sender;
- (IBAction)suspendAIPressed:(id)sender;

- (void) onLocalMoveMadeFrom:(Position)from toPosition:(Position)to;
- (void) saveGame;

- (void) goBackToHomeMenu;

@end
