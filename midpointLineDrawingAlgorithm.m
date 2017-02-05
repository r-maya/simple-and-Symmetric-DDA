xa=input('enter X1.\n');
ya=input('enter Y1. \n');
xb=input('enter X2.\n');
yb=input('enter Y2. \n');

x = xa;
y = ya;
dy = yb-ya;
dx = xb-xa;
d = 2*dy-dx; 
dde = 2*dy; 
ddne = 2*(dy-dx);

hold on
plot(x,y,'.');

while x<xb
    if(d<0)
            d = d+dde;
    else
            d = d+ddne;
            y = y+1;
    end
    plot(x, y, '.');
x = x+1;
end
hold off