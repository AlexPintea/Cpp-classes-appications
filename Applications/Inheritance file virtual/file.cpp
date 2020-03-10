class class_file : public class_file_inheritance
{
	virtual void sub() = 0;
	virtual void sub2() = 0;
}

class class_file_1 : public class_file_inheritance
{
	virtual void sub() = 0;
}
