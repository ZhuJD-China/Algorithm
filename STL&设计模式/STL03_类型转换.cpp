C����ǿ������ת��(Type Cast)�ܼ򵥣�����ʲô���͵�ת��ͳͳ�ǣ�

����TYPE b = (TYPE)a


����C++��������ת���ṩ��4������ת����������Ӧ�Բ�ͬ���ϵ�Ӧ�á�

����const_cast��������������ȥconst���ԡ�

����static_cast������������Ǿ�̬����ת������intת����char��

����dynamic_cast������������Ƕ�̬����ת����������͸���֮��Ķ�̬����ת����

����reinterpreter_cast���������½������ͣ���û�н��ж����Ƶ�ת����

����4������ת���ĸ�ʽ���磺


����TYPE B = static_cast(TYPE)(a)


����const_cast

����ȥ�����͵�const��volatile���ԡ�


����struct SA {

����int i;

����};

����const SA ra;

����//ra.i = 10; //ֱ���޸�const���ͣ��������

����SA &rb = const_castSA&>(ra);

����rb.i = 10;


����static_cast

����������C����ǿ��ת����������ת������̬����ת�������ڣ�

����1. ���������֮��ת������������ָ��ת���ɸ���ָ���ǰ�ȫ��;������ָ��ת��������ָ���ǲ���ȫ�ġ�
        (���������֮��Ķ�̬����ת��������dynamic_cast)

����2. ������������ת����enum, struct, int, char, float�ȡ�static_cast���ܽ����޹�����(��ǻ��������)ָ��֮���ת����

����3. �ѿ�ָ��ת����Ŀ�����͵Ŀ�ָ�롣

����4. ���κ����͵ı��ʽת����void���͡�

����5. static_cast����ȥ�����͵�const��volitale����(��const_cast)��

����


����int n = 6;

����double d = static_castdouble>(n); // ��������ת��

����int *pn = &n;

����double *d = static_castdouble *>(&n) //�޹�����ָ��ת�����������

����void *p = static_castvoid *>(pn); //��������ת����void����


����dynamic_cast

����������ת������̬����ת��������ʱ���Ͱ�ȫ���(ת��ʧ�ܷ���NULL)��

����1. ��ȫ�Ļ��������֮��ת����

����2. ����Ҫ���麯����

����3. ��ͬ���಻ͬ����֮��Ľ���ת�����������NULL��

����


����class BaseClass {

����public:

����int m_iNum;

����virtual void foo(){};

����//����������麯�������ֶ�̨���Բ���ʹ��dynamic_cast

����};

����class DerivedClass: public BaseClass {

����public:

����char *m_szName[100];

����void bar(){};

����};

����BaseClass* pb = new DerivedClass();

����DerivedClass *pd1 = static_castDerivedClass *>(pb);

����//����->���࣬��̬����ת������ȷ�����Ƽ�

����DerivedClass *pd2 = dynamic_castDerivedClass *>(pb);

����//����->���࣬��̬����ת������ȷ

����BaseClass* pb2 = new BaseClass();

����DerivedClass *pd21 = static_castDerivedClass *>(pb2);

����//����->���࣬��̬����ת����Σ�գ���������m_szName��ԱԽ��

����DerivedClass *pd22 = dynamic_castDerivedClass *>(pb2);

����//����->���࣬��̬����ת������ȫ�ġ������NULL


����reinterpreter_cast

�����������½������ͣ���û�н��ж����Ƶ�ת����

����1. ת�������ͱ�����һ��ָ�롢���á��������͡�����ָ����߳�Աָ�롣

����2. �ڱ���λ�����Ͻ���ת���������԰�һ��ָ��ת����һ��������Ҳ���԰�һ������ת����һ��ָ��
    (�Ȱ�һ��ָ��ת����һ���������ڰѸ�����ת����ԭ���͵�ָ�룬�����Եõ�ԭ�ȵ�ָ��ֵ)�������ܽ���32bit��ʵ��ת��ָ�롣

����3. ����ͨ����;�����ں���ָ������֮�����ת����

����4. ���ѱ�֤��ֲ�ԡ�

����


����int doSomething(){return 0;};

����typedef void(*FuncPtr)();

����//FuncPtr is һ��ָ������ָ�룬�ú���û�в���������ֵ����Ϊ void

����FuncPtr funcPtrArray[10];

����//10��FuncPtrsָ������� �����Ǽ�����ϣ������ΪĳЩĪ�������ԭ�򣩰�һ��ָ�����溯����ָ�����funcPtrArray���飺

����funcPtrArray[0] = &doSomething;

����// ����������Ͳ�ƥ�䣬reinterpret_cast�����ñ���������ķ���ȥ�������ǣ�funcPtrArray

����funcPtrArray[0] = reinterpret_castFuncPtr>(&doSomething);

����//��ͬ����ָ������֮�����ת��


������ ��

����ȥconst������const_cast��

������������ת����static_cast��

������̬��֮�������ת����daynamic_cast��

������ͬ���͵�ָ������ת����reinterpreter_cast��
