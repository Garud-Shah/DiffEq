import graph;
size(150,0);
    real f(real x) {return 1/x;}
    pair F(real x) {return (x,f(x));}
    draw(graph(f,-10,10,operator ..),red);
    real f(real x) {return -1/x;}
    pair F(real x) {return (x,f(x));}
    draw(graph(f,-10,10,operator ..),red);
    xaxis("$x$");
    yaxis("$y$",0);
    
    label("$e^x$",F(1),SE);

