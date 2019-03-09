
void partC(unsigned char(*)[], unsigned char, short);

main()
{
	unsigned char image[4][4]={{10, 100, 68, 80},
	               {76, 45, 69, 250},
	               {23, 56, 11, 129},
	               {87, 156, 178, 13}};
	unsigned char thres = 50;
	short length = 16;

	partC(image, thres, length);
}
