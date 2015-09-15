function [L, U] = e_gauss_wagner_s_pivot(A)
[m,m] = size(A);
tic();
for k=1:m-1
	A(k+1:m, k) = A(k+1:m, k)/A(k,k);
	A(k+1:m, k+1:m) = A(k+1:m, k+1:m) - A(k+1:m, k) * A(k, k+1:m);
end
toc();
U = triu(A); #Pega a parte superior de A (triu = triangular upper)
A(logical(eye(m))) = 1; #Faz todos os elementos da diagonal de A virarem 1
L = tril(A); #Agora com a diagonal principal de A com elementos iguais a 1, pega a parte inferior de A (tril = triangular lower)
endfunction
