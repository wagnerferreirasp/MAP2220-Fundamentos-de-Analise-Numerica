function [L, U] = e_gauss_s_pivot(A)
#algoritmo de eliminação de Gauss sem pivotamento - Professor
[m,n] = size(A);
U = A;
L = eye(m,m);
for k=1:m-1
	printf("Para k = %d\n", k);
    for j=k+1:m
		printf("Para j = %d\n", j);
		printf("Atualizando L(j,k) = L(%d, %d) para: ", j, k);
        L(j,k) = U(j,k)/U(k,k)
		printf("\n");
		printf("Atualizando a linha j = %d, colunas de k = %d até m = %d para: ", j, k, m);
        U(j,k:m)=U(j,k:m)-L(j,k)*U(k,k:m)
    end
end
endfunction
