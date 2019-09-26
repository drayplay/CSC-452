np = 1e7;nd = 10;nl = 8;
tic;
hp = gcp('nocreate');
if isempty(hp), hp = parpool(nl);end
spmd
    A = randn(np/nl,nd); B = randn(np/nl,nd);
    d = zeros(np/nl,1);
    tic;
    for i = 1:np/8
        for j = 1:nd
             d(i) = d(i) + (B(i,j)-A(i,j)).^2;
        end
        d(i) = sqrt(d(i));
    end
    da = gcat(d,1,1);
    
end
t = toc;
d1 = da{1};
delete(hp);