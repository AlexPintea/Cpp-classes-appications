// 


//void sort_by_size (int a[])
{
	int size = length(a);

	int digits[ size + 1 ];

	for (int i=0; i<size; i=i+1)
//		digits[i] = num_digits[ a[i] ]; // 

	for (int i=0; i<size; i=i+1)
		cout << digits[i] << " ";
	cout << endl;

		for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
		{			
			if ( digits[i] == digits[k] && a[i] > a[k] )
			{
				swap(a[i], a[k]);
				continue;
			}

			if ( digits[i] > digits[k] )			
			{
				swap(digits[i], digits[k]);
				swap(a[i], a[k]);
			}
		}
}







//void sort_by_size (string a[])
{

}

