//#include <stdio.h>
//
//double maxANDmin(double* arr, int len, char ch, double m) {	
//	for (int i = 0; i < len; i++) {
//		if (ch == '1')
//			if (m > arr[i])
//				m = arr[i];
//		else
//			if (m < arr[i])
//				m = arr[i];
//	}
//	return m;
//}
//int NoRain(int* arr, int len) {
//	int cntNR = 0;
//	for (int i = 0; i < len; i++)
//		if (arr[i] == 0.0)
//			cntNR++;
//	return cntNR;
//}
//double MidleRain(int* arr, int len) {
//	double midle = 0;
//	for (int i = 0; i < len; i++)
//		midle += arr[i];
//	return midle / len;
//}
//double MidleOfMaxRain(int* arr, int len) {
//	double cntMR[30] = { 0 }; int cnt = 0;
//	for (int i = 0; i < len; i++)
//		if (arr[i] >= 100.0) {
//			cntMR[i] = arr[i];
//			cnt++;
//		}
//
//	double MRvalue = 0.0;
//	for (int i = 0; i < len; i++)
//		if (cntMR[i] != 0.0)
//			MRvalue += cntMR[i];
//
//	return MRvalue / cnt;
//}
//void MaxAndMinAndData(int* arr, int len) {
//	double max = maxANDmin(arr, len, '1', 0.0);
//	double min = maxANDmin(arr, len, '0', 1000.0);
//	printf("max: %lf\n", max);
//	printf("min: %lf\n", min);
//	/*for (int i = 0; i < len; i++)
//	{
//
//	}*/
//}
//void DataLowMidlerain(int* arr, int len) {
//
//}
//int main() {
//	 double month[30] = { 50.2 , 6.7 , 90.0 , 104.0 , 0.0 , 41.6 , 55.2 , 117.7 , 0.0 , 0.0 , 0.0 , 0.0 , 95.3 , 25.2 , 52.7 , 6.1 , 62.1 , 72.7 , 6.7 , 105.3 , 52.2 , 0.8 , 32.1 , 18.8 , 63.6 , 28.3 , 82.6 , 77.9 , 54.2 };
//	 int len = *(&month + 1) - month;
//	 printf("No rain: %d\n", NoRain(month, len));
//	 printf("Midle value: %lf\n", MidleRain(month, len));
//	 printf("Midle of max rains: %lf\n", MidleOfMaxRain(month, len));
//	 MaxAndMinAndData(month, len);
//	 DataLowMidlerain(month, len);
//	return 0;
//}