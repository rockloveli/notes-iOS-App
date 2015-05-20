//
//  OCNoteOperation.h
//  iOCNotes
//

/************************************************************************
 
 Copyright 2015 Peter Hedlund peter.hedlund@me.com
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:
 
 1. Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR
 IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 *************************************************************************/

#import <Foundation/Foundation.h>
#import "OCNote.h"

typedef NS_ENUM(NSInteger, NoteOperationType) {
    NoteOperationTypeAdd,
    NoteOperationTypeUpdate,
    NoteOperationTypeGet,
    NoteOperationTypeDelete
};

@protocol OCNoteOperationDelegate;

@interface OCNoteOperation : NSOperation
{
    id <OCNoteOperationDelegate> __unsafe_unretained delegate;
}

- (id)initWithNote:(OCNote *)note noteOperationType:(NoteOperationType)operationType delegate:(id<OCNoteOperationDelegate>)delegate;

@property (nonatomic, unsafe_unretained) id <OCNoteOperationDelegate> delegate;
@property (nonatomic, strong, readonly) OCNote *note;
@property (nonatomic, strong, readonly) NSString *errorMessage;
@property (nonatomic, strong, readonly) NSDictionary *responseDictionary;
@property (nonatomic, assign) NoteOperationType noteOperationType;

@end

@protocol OCNoteOperationDelegate <NSObject>

@optional
- (void)noteOperationDidStart:(OCNoteOperation *)noteOperation;
- (void)noteOperationDidFinish:(OCNoteOperation *)noteOperation;
- (void)noteOperationDidFail:(OCNoteOperation *)noteOperation;

@end