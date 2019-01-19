#include <iostream>
char *itoa(int val, char *buf, unsigned radix)
{
	char   *p;
	char   *firstdig;
	char   temp;
	unsigned   digval;
	p = buf;
	if (val <0)
	{
		*p++ = '-';
		val = (unsigned long)(-(long)val);
	}
	firstdig = p;
	do {
		digval = (unsigned)(val % radix);
		val /= radix;

		if (digval > 9)
			*p++ = (char)(digval - 10 + 'a');
		else
			*p++ = (char)(digval + '0');
	} while (val > 0);

	*p-- = '\0 ';
	do {
		temp = *p;
		*p = *firstdig;
		*firstdig = temp;
		--p;
		++firstdig;
	} while (firstdig < p);
	return buf;
}
int main() {
	char A[99];
	char B[99];
	std::cin >> A;
	int i = 0;
	int sum = 0;
	while (A[i] != '\0') {
		sum += ((int)A[i]-48);
		i++;
	}
	int j = 0;
	//std::cout << sum;
	itoa(sum, B, 10);
	while (B[j+1] != '\0') {
		switch (B[j])
		{
		case '0':std::cout << "ling";
			break;
		case '1':std::cout << "yi";
			break;
		case '2':std::cout << "er";
			break;
		case '3':std::cout << "san";
			break;
		case '4':std::cout << "si";
			break;
		case '5':std::cout << "wu";
			break;
		case '6':std::cout << "liu";
			break;
		case '7':std::cout << "qi";
			break;
		case '8':std::cout << "ba";
			break;
		case '9':std::cout << "jiu";
			break;
		default:
			break;
		}
		j++;
		std::cout << ' ';
	}
	switch (B[j])
	{
	case '0':std::cout << "ling";
		break;
	case '1':std::cout << "yi";
		break;
	case '2':std::cout << "er";
		break;
	case '3':std::cout << "san";
		break;
	case '4':std::cout << "si";
		break;
	case '5':std::cout << "wu";
		break;
	case '6':std::cout << "liu";
		break;
	case '7':std::cout << "qi";
		break;
	case '8':std::cout << "ba";
		break;
	case '9':std::cout << "jiu";
		break;
	default:
		break;
	}
	//std::cout << std::endl;
	system("pause");
	return 0;
}
