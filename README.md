# QGraphviz
A Graphviz-based QT project.  
And this project is Mr. Yang's project assignment.
## preface
Graphviz is an open-source graph visualization tool that is great for drawing structured icons and networks. Graphviz uses a language called DOT to represent graphs. A few simple lines of commands can draw beautiful graphics. However, when users need to process a large amount of data, using Graphviz's DOT language compiler GVEdit will consume a lot of time, because the user needs to write every node and relationship to the DOT script. To this end, the author combines the requirements of the topic and the needs of users, uses C++ to encapsulate common DOT commands into classes, and uses Qt to draw UI interfaces to meet the drawing needs of large scale, complex relationships and beautiful styles, so as to make the program more practical.
## Instructions for use
1.Graphviz's environment variables need to be deployed  
2.You need to modify the path to the lib file in your .pro file  
3.My programming level may not be very good, there may be unknown bugs  
4.Free mode means that the user enters or imports the data on their own, where the data comes in pairs, the former is the pre-node and the latter is the post-node, and the program will iterate through the data sequentially and create their relationships accordingly. This allows arbitrarily complex diagrams to be realized;  
Tree mode is a mode of rapid generation tree diagram written for students learning data structures and discrete mathematics, which is very convenient to draw a tree in the daily learning process to quickly take notes or help think about problems. Users only need to enter or import the tree sequence traversal data, and they can quickly draw a tree map for use. Of course, tree mode can also quickly generate tree-like diagrams such as family trees.

