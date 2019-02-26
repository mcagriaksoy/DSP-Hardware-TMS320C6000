i = 1:800;
SinTable1 = sin(2*pi*(i/800));

fid = fopen('sinTable.h','wb');
fprintf(fid,'float sineTable[800] = {')

for i=1:800
    
    fprintf(fid,'%f,',SinTable1(i));
    
end
plot(SinTable1);
fprintf(fid,'};')
fclose(fid);
