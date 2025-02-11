package compiler;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

import ast.ArrayExpr;
import ast.BinaryExpr;
import ast.Decl;
import ast.Expr;
import ast.IdentExpr;
import ast.Program;
import ast.Types;
import parser.ParserWrapper;

public class Compiler {
    // Process return codes
    public static final int EXIT_SUCCESS = 0;
    public static final int EXIT_PARSING_ERROR = 1;
    public static final int EXIT_SEMANTIC_CHECKING_ERROR = 2;
    public static void main(String[] args) {
        String filename = args[0];
        Program astRoot = null;
        BufferedReader reader;
        try {
            reader = new BufferedReader(new FileReader(filename));
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
        try {
	    astRoot = ParserWrapper.parse(reader,filename);
        } catch (Exception ex) {
            fatalError("Uncaught parsing error: " + ex, EXIT_PARSING_ERROR);
        }
	
        //Add Semantic Check
        astRoot.check();

        // Simplistic pretty printing of the AST
        astRoot.print(System.out);
        
        System.exit(EXIT_SUCCESS);
    }
    public static void fatalError(String message, int processReturnCode) {
        System.out.println(message);
        System.exit(processReturnCode);
    }

    public static void setSymbolTableVariableType(Expr expr) {
        String id = "";
        if(expr instanceof IdentExpr identExpr){
            id = identExpr.id;
        }else if(expr instanceof ArrayExpr arrayExpr) {
            id = arrayExpr.id;
        }
        
        Decl varDecl = Program.symbolTable.get(id);
        expr.type = varDecl.type;
    }

    public static int expressionReturnTypeCheck(BinaryExpr bExpr){
        bExpr.expr1.check();
        bExpr.expr2.check();

        //Type Conversions
        return operatorWidening(bExpr);
    }

    public static int operatorWidening(BinaryExpr bExpr) {
        List<Integer> binaryOperators = Arrays.asList(1,2,4,5,12,13,14,15,16,17);
        List<Integer> assignments = Arrays.asList(3,7,8,9,10);
        List<Integer> moduloOperators = Arrays.asList(6,11);

        String expr1Type = Types.toString(bExpr.expr1.type);
        String expr2Type = Types.toString(bExpr.expr2.type);

        if(binaryOperators.contains(bExpr.op)){
            //Binary Operator Type Return
            if(Types.toString(bExpr.expr2.type).equals("int")){
                return bExpr.expr1.type;
            }else{
                return Types.DOUBLE;
            }
        }else if (moduloOperators.contains(bExpr.op)) {
            //Modulo Type Return
            if( !(expr1Type.equals("int") && expr2Type.equals("int")) ){
                fatalError("Type Conversion Error", EXIT_SEMANTIC_CHECKING_ERROR);
            }else{
                return Types.INT;
            }
        }else if(assignments.contains(bExpr.op)){
            //Check Assignments L-Value is IdentExpr or ArrayExpr
            if( !(bExpr.expr1 instanceof  IdentExpr || bExpr.expr1 instanceof ArrayExpr) ){
                fatalError("L-Value Not Correct For Assignment", EXIT_SEMANTIC_CHECKING_ERROR);
            }

            //Assignemnts Type Return Check
            if(expr1Type.equals("int") && expr2Type.equals("int") ) {
                return Types.INT;
            }else if((expr1Type.equals("double")  && expr2Type.equals("int") ) || (expr1Type.equals("double")  && expr2Type.equals("double") )){
                return  Types.DOUBLE;
            }else{
                fatalError("Type Conversion Error", EXIT_SEMANTIC_CHECKING_ERROR);
            }
        }

        return 0;
    }

    public static void checkArrayAttributes(ArrayExpr aExpr){
        //Get Array From Symbol Table
        Decl arrayDecl = Program.symbolTable.get(aExpr.id);

        //Check Dims of each, throw error if they dont match
        if(arrayDecl.dims.size() != aExpr.dims.size()){
            fatalError("Array Bounds Are Not Correct For Array Expression", EXIT_SEMANTIC_CHECKING_ERROR);
        }

        //Check Array Is indexed with Ints
		for(Expr d : aExpr.dims) {
			d.check();
			if(d.type != Types.INT){
				fatalError("Non Int Variable in Array Dimensions", EXIT_SEMANTIC_CHECKING_ERROR);
			}
		}

        //Add Array Access to Symbol Table
        addTempararyVariable(aExpr);
    }

    public static void addTempararyVariable(Expr expr) {
        //Create Temp Variable
        String varId = "_t" + Program.tempVarIndex++;
        Decl varDecl = new Decl(varId, expr.type, new LinkedList<Integer>());
        
        //Add To Symbol Table
        Program.symbolTable.put(varId, varDecl);
    }
}
