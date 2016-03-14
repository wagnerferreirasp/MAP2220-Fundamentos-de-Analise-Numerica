function [L, U] = e_gauss_s_pivot2(A)
[m,n] = size(A);
U = A;
L = eye(m,m);
for k=1:m-1
    for j=k+1:m
        L(j,k) = U(j,k)/U(k,k);
        U(j,k:m)=U(j,k:m)-L(j,k)*U(k,k:m);
    end
    printf("K = %d\n", k);
    L
    U
end
endfunction
