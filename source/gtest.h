
// ********************************************************************************************************************* //
//
//                                                  XML-Datenbindung
//
//         Generiert am: 22.09.2017 13:34:39
//       Generiert von: C:\Users\ATJHAS07\Documents\Embarcadero\Studio\Projekte\GTESTPlugin\xml\gtest.xsd
//   Einstellungen gespeichert in: C:\Users\ATJHAS07\Documents\Embarcadero\Studio\Projekte\GTESTPlugin\xml\gtest.xdb
//
// ********************************************************************************************************************* //

#ifndef   gtestH
#define   gtestH

#include <System.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>


// Forward-Deklarationen

__interface IXMLtestsuites;
typedef System::DelphiInterface<IXMLtestsuites> _di_IXMLtestsuites;
__interface IXMLTestSuiteType;
typedef System::DelphiInterface<IXMLTestSuiteType> _di_IXMLTestSuiteType;
__interface IXMLTestCaseType;
typedef System::DelphiInterface<IXMLTestCaseType> _di_IXMLTestCaseType;
__interface IXMLFailureType;
typedef System::DelphiInterface<IXMLFailureType> _di_IXMLFailureType;

// IXMLtestsuites

__interface INTERFACE_UUID("{78E407D4-81FC-4912-84E5-02F60F4A68FD}") IXMLtestsuites : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Eigenschaftszugriff
  virtual int __fastcall Get_tests() = 0;
  virtual int __fastcall Get_failures() = 0;
  virtual int __fastcall Get_disabled() = 0;
  virtual int __fastcall Get_errors() = 0;
  virtual System::UnicodeString __fastcall Get_timestamp() = 0;
  virtual System::UnicodeString __fastcall Get_time() = 0;
  virtual System::UnicodeString __fastcall Get_name() = 0;
  virtual _di_IXMLTestSuiteType __fastcall Get_testsuite(int Index) = 0;
  virtual void __fastcall Set_tests(int Value) = 0;
  virtual void __fastcall Set_failures(int Value) = 0;
  virtual void __fastcall Set_disabled(int Value) = 0;
  virtual void __fastcall Set_errors(int Value) = 0;
  virtual void __fastcall Set_timestamp(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_time(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_name(System::UnicodeString Value) = 0;
  // Methoden & Eigenschaften
  virtual _di_IXMLTestSuiteType __fastcall Add() = 0;
  virtual _di_IXMLTestSuiteType __fastcall Insert(const int Index) = 0;
  __property int tests = { read=Get_tests, write=Set_tests };
  __property int failures = { read=Get_failures, write=Set_failures };
  __property int disabled = { read=Get_disabled, write=Set_disabled };
  __property int errors = { read=Get_errors, write=Set_errors };
  __property System::UnicodeString timestamp = { read=Get_timestamp, write=Set_timestamp };
  __property System::UnicodeString time = { read=Get_time, write=Set_time };
  __property System::UnicodeString name = { read=Get_name, write=Set_name };
  __property _di_IXMLTestSuiteType testsuite[int Index] = { read=Get_testsuite };/* default */
};

// IXMLTestSuiteType

__interface INTERFACE_UUID("{A35D4CE9-8D80-4CEE-BD97-4B4E817F072F}") IXMLTestSuiteType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Eigenschaftszugriff
  virtual System::UnicodeString __fastcall Get_name() = 0;
  virtual int __fastcall Get_tests() = 0;
  virtual int __fastcall Get_failures() = 0;
  virtual int __fastcall Get_errors() = 0;
  virtual int __fastcall Get_disabled() = 0;
  virtual System::UnicodeString __fastcall Get_time() = 0;
  virtual _di_IXMLTestCaseType __fastcall Get_testcase(int Index) = 0;
  virtual void __fastcall Set_name(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_tests(int Value) = 0;
  virtual void __fastcall Set_failures(int Value) = 0;
  virtual void __fastcall Set_errors(int Value) = 0;
  virtual void __fastcall Set_disabled(int Value) = 0;
  virtual void __fastcall Set_time(System::UnicodeString Value) = 0;
  // Methoden & Eigenschaften
  virtual _di_IXMLTestCaseType __fastcall Add() = 0;
  virtual _di_IXMLTestCaseType __fastcall Insert(const int Index) = 0;
  __property System::UnicodeString name = { read=Get_name, write=Set_name };
  __property int tests = { read=Get_tests, write=Set_tests };
  __property int failures = { read=Get_failures, write=Set_failures };
  __property int errors = { read=Get_errors, write=Set_errors };
  __property int disabled = { read=Get_disabled, write=Set_disabled };
  __property System::UnicodeString time = { read=Get_time, write=Set_time };
  __property _di_IXMLTestCaseType testcase[int Index] = { read=Get_testcase };/* default */
};

// IXMLTestCaseType

__interface INTERFACE_UUID("{C16BF926-D51A-4CB7-A97C-4A9B0A2EB687}") IXMLTestCaseType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Eigenschaftszugriff
  virtual System::UnicodeString __fastcall Get_name() = 0;
  virtual System::UnicodeString __fastcall Get_status() = 0;
  virtual System::UnicodeString __fastcall Get_time() = 0;
  virtual System::UnicodeString __fastcall Get_classname() = 0;
  virtual _di_IXMLFailureType __fastcall Get_failure(int Index) = 0;
  virtual void __fastcall Set_name(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_status(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_time(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_classname(System::UnicodeString Value) = 0;
  // Methoden & Eigenschaften
  virtual _di_IXMLFailureType __fastcall Add() = 0;
  virtual _di_IXMLFailureType __fastcall Insert(const int Index) = 0;
  __property System::UnicodeString name = { read=Get_name, write=Set_name };
  __property System::UnicodeString status = { read=Get_status, write=Set_status };
  __property System::UnicodeString time = { read=Get_time, write=Set_time };
  __property System::UnicodeString classname = { read=Get_classname, write=Set_classname };
  __property _di_IXMLFailureType failure[int Index] = { read=Get_failure };/* default */
};

// IXMLFailureType

__interface INTERFACE_UUID("{7E409652-F6D6-4CC1-B3A4-CD7FD1C92D40}") IXMLFailureType : public Xml::Xmlintf::IXMLNode
{
public:
  // Eigenschaftszugriff
  virtual System::UnicodeString __fastcall Get_message() = 0;
  virtual System::UnicodeString __fastcall Get_type() = 0;
  virtual void __fastcall Set_message(System::UnicodeString Value) = 0;
  virtual void __fastcall Set_type(System::UnicodeString Value) = 0;
  // Methoden & Eigenschaften
  __property System::UnicodeString message = { read=Get_message, write=Set_message };
  __property System::UnicodeString type = { read=Get_type, write=Set_type };
};

// Forward-Deklarationen

class TXMLtestsuites;
class TXMLTestSuiteType;
class TXMLTestCaseType;
class TXMLFailureType;

// TXMLtestsuites

class TXMLtestsuites : public Xml::Xmldoc::TXMLNodeCollection, public IXMLtestsuites
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLtestsuites
  virtual int __fastcall Get_tests();
  virtual int __fastcall Get_failures();
  virtual int __fastcall Get_disabled();
  virtual int __fastcall Get_errors();
  virtual System::UnicodeString __fastcall Get_timestamp();
  virtual System::UnicodeString __fastcall Get_time();
  virtual System::UnicodeString __fastcall Get_name();
  virtual _di_IXMLTestSuiteType __fastcall Get_testsuite(int Index);
  virtual void __fastcall Set_tests(int Value);
  virtual void __fastcall Set_failures(int Value);
  virtual void __fastcall Set_disabled(int Value);
  virtual void __fastcall Set_errors(int Value);
  virtual void __fastcall Set_timestamp(System::UnicodeString Value);
  virtual void __fastcall Set_time(System::UnicodeString Value);
  virtual void __fastcall Set_name(System::UnicodeString Value);
  virtual _di_IXMLTestSuiteType __fastcall Add();
  virtual _di_IXMLTestSuiteType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLTestSuiteType

class TXMLTestSuiteType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLTestSuiteType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLTestSuiteType
  virtual System::UnicodeString __fastcall Get_name();
  virtual int __fastcall Get_tests();
  virtual int __fastcall Get_failures();
  virtual int __fastcall Get_errors();
  virtual int __fastcall Get_disabled();
  virtual System::UnicodeString __fastcall Get_time();
  virtual _di_IXMLTestCaseType __fastcall Get_testcase(int Index);
  virtual void __fastcall Set_name(System::UnicodeString Value);
  virtual void __fastcall Set_tests(int Value);
  virtual void __fastcall Set_failures(int Value);
  virtual void __fastcall Set_errors(int Value);
  virtual void __fastcall Set_disabled(int Value);
  virtual void __fastcall Set_time(System::UnicodeString Value);
  virtual _di_IXMLTestCaseType __fastcall Add();
  virtual _di_IXMLTestCaseType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLTestCaseType

class TXMLTestCaseType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLTestCaseType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLTestCaseType
  virtual System::UnicodeString __fastcall Get_name();
  virtual System::UnicodeString __fastcall Get_status();
  virtual System::UnicodeString __fastcall Get_time();
  virtual System::UnicodeString __fastcall Get_classname();
  virtual _di_IXMLFailureType __fastcall Get_failure(int Index);
  virtual void __fastcall Set_name(System::UnicodeString Value);
  virtual void __fastcall Set_status(System::UnicodeString Value);
  virtual void __fastcall Set_time(System::UnicodeString Value);
  virtual void __fastcall Set_classname(System::UnicodeString Value);
  virtual _di_IXMLFailureType __fastcall Add();
  virtual _di_IXMLFailureType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLFailureType

class TXMLFailureType : public Xml::Xmldoc::TXMLNode, public IXMLFailureType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLFailureType
  virtual System::UnicodeString __fastcall Get_message();
  virtual System::UnicodeString __fastcall Get_type();
  virtual void __fastcall Set_message(System::UnicodeString Value);
  virtual void __fastcall Set_type(System::UnicodeString Value);
};

// Globale Funktionen

_di_IXMLtestsuites __fastcall Gettestsuites(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLtestsuites __fastcall Gettestsuites(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLtestsuites __fastcall Loadtestsuites(const System::UnicodeString& FileName);
_di_IXMLtestsuites __fastcall  Newtestsuites();

#define TargetNamespace ""

#endif
