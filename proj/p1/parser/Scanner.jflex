package parser;

import java_cup.runtime.Symbol;
import java_cup.runtime.ComplexSymbolFactory;
import java_cup.runtime.ComplexSymbolFactory.Location;

import compiler.Compiler;

%%

%public
%class Lexer
%cup
%implements sym
%char
%line
%column

%{
    StringBuffer string = new StringBuffer();
    public Lexer(java.io.Reader in, ComplexSymbolFactory sf, String fn){
	this(in);
	symbolFactory = sf;
	filename = fn;
    }
    ComplexSymbolFactory symbolFactory;
    String filename;

  private Symbol symbol(String name, int sym) {
      return symbolFactory.newSymbol(name, sym, new Location(filename, yyline + 1, yycolumn + 1), new Location(filename, yyline + 1, yycolumn + yylength()));
  }

  private Symbol symbol(String name, int sym, Object val) {
      Location left = new Location(filename, yyline + 1, yycolumn + 1);
      Location right = new Location(filename, yyline + 1, yycolumn + yylength());
      return symbolFactory.newSymbol(name, sym, left, right, val);
  } 
%} 

%eofval{
     return symbolFactory.newSymbol("EOF", EOF, new Location(filename, yyline + 1, yycolumn + 1), new Location(filename, yyline + 1, yycolumn + 1));
%eofval}

/*** TODO START: Replace these placeholders with your own definitions ***/

/* Identifiers: TODO - make them general, as described in Section
 * 6.4.2.1 in the C spec. Ignore "universal-character-name" and
 * "other implementation-defined characters" mentioned in Section
 * 6.4.2.1.
 */
Ident = {identNonDigit} | ({Ident} {identNonDigit}) | ({Ident} {digit})
IdentNonDigit = {nondigit} //No definition for "universal-character-name" and "other implementation-defined characters"
Nondigit = [A-z_]
Digit = [0-9]

/* Integer literals: TODO - handle integer literals as described in
 * Section 6.4.4.1 of the C spec. For simplicity, do NOT
 * handle the 'long', 'long long', and 'unsigned' cases. 
 * But DO handle hexadecimal and octal constants. You do NOT need to 
 * change the scanner action associated with IntLiteral; that action
 * (later in this file) calls Integer.decode,  which should process 
 * correctly the matched literal. Assume the value fits in a Java int.
 */


IntLiteral = {DecimalConst} | {OctalConst} | {HexConst}
DecimalConst = {NonZeroDigit} | ({DecimalConst} {Digit})
OctalConst = 0 | ({OctalConst} {OctalDigit})
HexConst = ({HexPrefix} {HexDigit}) | ({HexConst} {HexDigit})

HexPrefix = [0x] | [0X]

NonZeroDigit = [1-9]
OctalDigit = [0-7]
HexDigit = [0-9A-Fa-f]

/* Floating point literals: TODO - handle floating point literals as 
 * described in Section 6.4.4.2 of the C spec. For
 * simplicity, do NOT handle the 'long double' cases. But DO handle
 * hexadecimal floating constants, e/E and p/P notation, and f/F
 * suffixes. You do NOT need to change the scanner action associated 
 * with DoubleLiteral; that action (later in this file) calls 
 * Double.valueOf, which should process correctly the matched literal. 
 * Assume the value fits in a Java double.
 */        

DoubleLiteral = {DecimalFloatConst} | {HexFloatConst}
DecimalFloatConst = ({FracConst} {ExpoPart}? {FloatSuffix}?) | ({DigitSeq} {ExpoPart} {FloatSuffix}?) 
HexFloatConst = ({HexPrefix} {HexFracConst} {BinaryExpPart} {FloatSuffix}?) | ({HexPrefix} {HexDigitSeq} {BinaryExpPart} {FloatSuffix})
FracConst = ({DigitSeq}? \. {DigitSeq}) | ({DigitSeq} \.) 
ExpoPart = ([e] {Sign}? {DigitSeq}) | ([E] {Sign}? {DigitSeq})
Sign = [\+] | [\-]
DigitSeq = {Digit} | ({DigitSeq} {Digit})
HexFracConst = ({HexDigitSeq} \. {HexDigitSeq}) | ({HexDigitSeq} \.)
BinaryExpPart = ([p] {Sign}? {DigitSeq}) | ([P] {Sign}? {DigitSeq})
HexDigitSeq = {HexDigit} | ({HexDigitSeq} {HexDigit})
FloatSuffix = [flFL]


/*** TODO END ***/

new_line = \r|\n|\r\n;
white_space = {new_line} | [ \t\f]
%%
<YYINITIAL>{

/* keywords */
"int"             { return symbol("int",         INT); }
"double"          { return symbol("double",      DOUBLE); }
"return"          { return symbol("return",      RETURN); }
"if"              { return symbol("if",          IF); }
"else"            { return symbol("else",        ELSE); }

/* literals */
{IntLiteral}    { return symbol("Intconst", INTCONST, Integer.decode(yytext())); }
{DoubleLiteral} { return symbol("Doubleconst", DOUBLECONST, Double.valueOf(yytext())); }

/* names */
{Ident}           { return symbol("ID", IDENT, yytext()); }

/* punctuators */
";"               { return symbol(";",  SEMICOLON); }
"("               { return symbol("(",  LPAREN); }
")"               { return symbol(")",  RPAREN); }
"["               { return symbol("[",  LBRACK); }
"]"               { return symbol("]",  RBRACK); }
"{"               { return symbol("{",  LBRACE); }
"}"               { return symbol("}",  RBRACE); }

/*** TODO START: Add more operators ***/

"="               { return symbol("=",  ASSIGN); }
"+"               { return symbol("+",  PLUS); }
"*"               { return symbol("*",  MUL); }
"-"               { return symbol("-",  SUB); }
"/"               { return symbol("/",  DIVIDE); }
"%"               { return symbol("%",  MODULO); }
"+="              { return symbol("+=",  PLUSASSIGN); }
"-="              { return symbol("-=",  SUBASSIGN); }
"*="              { return symbol("*=",  MULASSIGN); }
"/="              { return symbol("/=",  DIVIDEASSIGN); }
"%="              { return symbol("%=",  MODULOASSIGN); }

/*** TODO END ***/

"/*" [^*] ~"*/" | "/*" "*"+ "/"
                  { /* ignore comments */ }

{white_space}     { /* ignore */ }

}

/* error fallback */
[^]               { Compiler.fatalError("Illegal character <" + yytext() + ">", Compiler.EXIT_PARSING_ERROR); }
