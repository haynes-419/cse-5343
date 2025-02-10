package compiler;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import ast.Program;
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
            reader = new BufferedReader(new FileReader("s1.c"));
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
}
