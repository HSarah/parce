
#ifndef OBJC_SCANNER_ACTIONS_H
#define OBJC_SCANNER_ACTIONS_H


/*
 *  parce: objc_scanner_actions.h
 *
 *  Copyright 2007 Bored Astronaut Software. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */


#include "objc_parser.h" // file generated by Bison including type symbols

void count();

/*
 The scan... functions create tokens which are stored in yylval.
 
 The pure C parser will ignore comments and white space but will fail with an error when it encounters a cpp macro.
 
 The Objective-C Parser framework will handle comments, whitespace and macros without the aid of the generated parser.
 */

extern void scanMacro();

extern void scanCommentBlock();
extern void scanCommentLine();
extern void scanWhiteSpace();

extern int scanConstant( char *tokenString );    // CONSTANT
extern int scanCString( char *tokenString );     // STRING_LITERAL
extern int scanObjCString( char *tokenString );  // OBJC_STRING_LITERAL

/*
 An identifier is stored in a context table as a specialized type determined by the parser, and retrieved on subsequent occurrences
 */
extern int scanType( char *tokenString );        // IDENTIFIER->TYPE_NAME/CLASS_NAME/PROTOCOL_NAME/CATEGORY_NAME

#endif /* OBJC_SCANNER_ACTIONS_H */