++++[>++++[>+++<-]<-]       // Writing the ASCII value for '0' (48) to cell(2)
,>,>                        // Reading two numbers into cell(0) and cell(1)
[<-<->>-]                   // Decrementing cell(0) and cell(1) by the ASCII value for '0' (48)
<<                          // Move to cell(0)
[                           // Multiplication loop
    >                       // Move to cell(1)
    [>+>+<<-]               // Move cell(1) to cell(2) and cell(3)
    >>                      // Move to cell(3)
    [<<+>>-]                // Move cell(3) back to cell(1)
    <<<-                    // Decrement cell(0)
]
>[-]<                       // Set cell(1) to 0 (used as a counter, currently in cell 0)
++++[>++++[>+++<-]<-]       // Adding the ASCII value for '0' (48) to cell(2)
>>.                         // Print the result (go to cell 2 and print)

