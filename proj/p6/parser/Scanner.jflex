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

/* Identifiers */
Ident = {IdentNonDigit} ({Digit} | {Nondigit})*
IdentNonDigit = {Nondigit} //No definition for "universal-character-name" and "other implementation-defined characters"
Nondigit = [_A-Za-z]
Digit = [0-9]

/* Integer literals */
IntLiteral = {DecimalConst} | {OctalConst} | {HexConst}
DecimalConst = {NonZeroDigit} {Digit}* //At least one nonleading 0, zero+ digits
OctalConst = 0 {OctalDigit}* //Octal Can be Just 0 
HexConst = {HexPrefix} {HexDigit}+

HexPrefix = 0x | 0X
NonZeroDigit = [1-9]
OctalDigit = [0-7]
HexDigit = [0-9A-Fa-f]

/* Floating point literals */        
DoubleLiteral = {DecimalFloatConst} | {HexFloatConst}
DecimalFloatConst = ({FracConst} {ExpoPart}? {FloatSuffix}?) | ({DigitSeq} {ExpoPart} {FloatSuffix}?) 
HexFloatConst = ({HexPrefix} {HexFracConst} {BinaryExpPart} {FloatSuffix}?) | ({HexPrefix} {HexDigitSeq} {BinaryExpPart} {FloatSuffix}?)
FracConst = ({DigitSeq}? \. {DigitSeq}) | ({DigitSeq} \.) 
ExpoPart = ([e] {Sign}? {DigitSeq}) | ([E] {Sign}? {DigitSeq})
Sign = [\+] | [\-]
DigitSeq = {Digit}+
HexFracConst = ({HexDigitSeq}? \. {HexDigitSeq}) | ({HexDigitSeq} \.)
BinaryExpPart = ((p|P) {Sign}? {DigitSeq})
HexDigitSeq = {HexDigit}+
FloatSuffix = [fF]

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
"while"           { return symbol("while",       WHILE); }
"for"             { return symbol("for",         FOR); }
"goto"            { return symbol("goto",        GOTO); }

/* literals */
{IntLiteral}    { return symbol("Intconst", INTCONST, Integer.decode(yytext())); }
{DoubleLiteral} { return symbol("Doubleconst", DOUBLECONST, Double.valueOf(yytext())); }

/* names */
{Ident}           { return symbol("ID", IDENT, yytext()); }

/* punctuators */
";"               { return symbol(";",  SEMICOLON); }
":"               { return symbol(":",  COLON); }
"("               { return symbol("(",  LPAREN); }
")"               { return symbol(")",  RPAREN); }
"["               { return symbol("[",  LBRACK); }
"]"               { return symbol("]",  RBRACK); }
"{"               { return symbol("{",  LBRACE); }
"}"               { return symbol("}",  RBRACE); }
"!"               { return symbol("!",  NOT); }

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

"<"               { return symbol("<",  LESSTHEN); }
"<="              { return symbol("<=",  LESSTHENEQUAL); }
">"               { return symbol(">",  GREATERTHEN); }
">="              { return symbol(">=",  GREATERTHENEQUAL); }
"=="              { return symbol("==",  EQUALEQUAL); }
"!="              { return symbol("!=",  NOTEQUAL); }

"/*" [^*] ~"*/" | "/*" "*"+ "/"
                  { /* ignore comments */ }

{white_space}     { /* ignore */ }

}

/* error fallback */
[^]               { Compiler.fatalError("Illegal character <" + yytext() + ">", Compiler.EXIT_PARSING_ERROR); }
