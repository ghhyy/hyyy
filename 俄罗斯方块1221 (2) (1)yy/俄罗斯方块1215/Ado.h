#ifndef _ADO_H_
#define _ADO_H_

#import "C:\Program Files\Common Files\System\ado\msado60_Backcompat_i386.tlb" no_namespace rename("EOF","adoEOF")\
	rename("LockTypeEnum","adoLockTypeEnum")\
	rename("FieldAttributeEnum","adoFieldAtttributeEnum")\
	rename("EditModeEnum","adoEditModeEnum")\
	rename("RecordStatusEnum","adoRecordStatusEnum")\
	rename("ParameterDirectionEnum","adoParameterDirectionEnum")\
	rename("DataTypeEnum","adoDataTypeEnum")
//#import ".\ado\msado15.dll" no_namespace rename("EOF","adoEOF")
class CAdo//:public CSingleton<CAdo>
{
public:
	static CAdo& getSingleton()
	{
		static CAdo mInstance;
		return mInstance;
	}
public:
	_RecordsetPtr m_pRecordset;
	_ConnectionPtr m_pConnection;

public:
	//构造函数
	CAdo();
	//析构函数
	virtual ~CAdo();

	//access数据库引擎打开
	void OnInitADOConn();
	void OnInitADOConn(CString sourcePath);

	//SqlServer 数据库引擎打开
	void OnInitADOConnSQLServer();

public:

	//查询语句获取记录集
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	_RecordsetPtr& GetRecordSet(CString strSQL);

	//执行sql语句
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	BOOL ExecuteSQL(CString strSQL);
	
	//从某一个字段读取数据
	CString GetCollect(CString strField);
	CString GetCollect(CString strField,_RecordsetPtr& recordSet);

	//释放连接
	void ExitConnect();
	
	//显示错误信息
	void ExpressErrInfo(_com_error e);
};

#endif	//_ADO_H_