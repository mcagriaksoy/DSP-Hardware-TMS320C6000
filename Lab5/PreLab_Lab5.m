%Author Mehmet Cagri Aksoy

sample_rate = 16000;
cutoff_freq = 1000;


nyq_freq = sample_rate / 2;
norm = cutoff_freq / nyq_freq;

% FIR filter order 1
order = 10;

% fir1 uses a Hamming window to design an nth-order lowpass, 
%bandpass, or multiband FIR filter with linear phase. 
%The filter type depends on the number of elements of Wn.

b = fir1(order, norm);

% show
freqz(b,1)
figure

% open file
fil = fopen('coeffTable.h','wt');

%writing process to the file:
fprintf(fil,'float fir_10[11] = {')

for j = 1:size(b,1)

	fprintf(fil,'%f,',b(j,:));
end

fprintf(fil,'};\n')


% FIR filter order 2

order = 30;

% filter coefficients, there are (number of sample+1)

b = fir1(order, norm);

% show
freqz(b,1)
figure
fprintf(fil,'float fir_30[31] = {')

for j = 1:size(b,1)

	fprintf(fil,'%f,',b(j,:));
end

fprintf(fil,'};\n')

% FIR filter order 3
order = 50;


b = fir1(order, norm);

% show
freqz(b,1)

fprintf(fil,'float fir_50[51] = {')

for j = 1:size(b,1)

	fprintf(fil,'%f,',b(j,:));
end

fprintf(fil,'};')


fclose(fil)
