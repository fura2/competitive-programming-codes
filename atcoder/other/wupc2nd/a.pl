($n,$m)=split(/\s/,<>);
print $n*($n+1)*(2*$n+1)/6%$m,"\n";
