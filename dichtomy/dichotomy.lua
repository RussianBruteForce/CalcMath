eps = 1e-6

function myDichotomy(a, b, fun, prec)
    while b - a > prec do
        c = (a + b) / 2;
        if fun(c) >= 0 then
            b = c;
        else
            a = c;
        end
    end 
    return (a+b)/2
end

-- Just simple check
sqrt2 = function(x)
    return x*x - 2
end

-- Trigonometry
sinXPlusPiPow2PlusX = function(x)
    return math.sin(x) - 2/3
end

-- Hyperbole
xPow2DivXPlus1 = function(x)
    return  math.pow(x, 2)/(x+1) - 5
end

-- Composite function
sqrtXPow3Min12X = function(x)
    return math.sqrt(9*math.pow(x, 3) - 12*x + 5) + 20
end

-- Using %f for tail reduction
print(string.format('%f',myDichotomy(0, 2, sqrt2, eps)))
    
-- In radians
print(string.format('%f radian',myDichotomy(-math.pi, math.pi, sinXPlusPiPow2PlusX, eps)))

print(string.format('%f',myDichotomy(0, 10, xPow2DivXPlus1, eps)))
    
print(string.format('%f',myDichotomy(-5, 5, sqrtXPow3Min12X, eps)))
    
