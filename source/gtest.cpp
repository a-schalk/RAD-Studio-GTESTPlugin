
// ********************************************************************************************************************* //
//
//                                                  XML-Datenbindung
//
//         Generiert am: 22.09.2017 13:34:39
//       Generiert von: C:\Users\ATJHAS07\Documents\Embarcadero\Studio\Projekte\GTESTPlugin\xml\gtest.xsd
//   Einstellungen gespeichert in: C:\Users\ATJHAS07\Documents\Embarcadero\Studio\Projekte\GTESTPlugin\xml\gtest.xdb
//
// ********************************************************************************************************************* //

#include <System.hpp>
#pragma hdrstop

#include "gtest.h"


// Globale Funktionen

_di_IXMLtestsuites __fastcall Gettestsuites(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLtestsuites) Doc->GetDocBinding("testsuites", __classid(TXMLtestsuites), TargetNamespace);
};

_di_IXMLtestsuites __fastcall Gettestsuites(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Gettestsuites(DocIntf);
};

_di_IXMLtestsuites __fastcall Loadtestsuites(const System::UnicodeString& FileName)
{
  return (_di_IXMLtestsuites) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("testsuites", __classid(TXMLtestsuites), TargetNamespace);
};

_di_IXMLtestsuites __fastcall  Newtestsuites()
{
  return (_di_IXMLtestsuites) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("testsuites", __classid(TXMLtestsuites), TargetNamespace);
};

// TXMLtestsuites

void __fastcall TXMLtestsuites::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("testsuite"), __classid(TXMLTestSuiteType));
  ItemTag = "testsuite";
  ItemInterface = __uuidof(IXMLTestSuiteType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

int __fastcall TXMLtestsuites::Get_tests()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("tests")]->NodeValue.operator int();
};

void __fastcall TXMLtestsuites::Set_tests(int Value)
{
  SetAttribute(System::UnicodeString("tests"), Value);
};

int __fastcall TXMLtestsuites::Get_failures()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("failures")]->NodeValue.operator int();
};

void __fastcall TXMLtestsuites::Set_failures(int Value)
{
  SetAttribute(System::UnicodeString("failures"), Value);
};

int __fastcall TXMLtestsuites::Get_disabled()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("disabled")]->NodeValue.operator int();
};

void __fastcall TXMLtestsuites::Set_disabled(int Value)
{
  SetAttribute(System::UnicodeString("disabled"), Value);
};

int __fastcall TXMLtestsuites::Get_errors()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("errors")]->NodeValue.operator int();
};

void __fastcall TXMLtestsuites::Set_errors(int Value)
{
  SetAttribute(System::UnicodeString("errors"), Value);
};

System::UnicodeString __fastcall TXMLtestsuites::Get_timestamp()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("timestamp")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLtestsuites::Set_timestamp(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("timestamp"), Value);
};

System::UnicodeString __fastcall TXMLtestsuites::Get_time()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("time")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLtestsuites::Set_time(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("time"), Value);
};

System::UnicodeString __fastcall TXMLtestsuites::Get_name()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("name")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLtestsuites::Set_name(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("name"), Value);
};

_di_IXMLTestSuiteType __fastcall TXMLtestsuites::Get_testsuite(int Index)
{
  return (_di_IXMLTestSuiteType) List->Nodes[Index];
};

_di_IXMLTestSuiteType __fastcall TXMLtestsuites::Add()
{
  return (_di_IXMLTestSuiteType) AddItem(-1);
};

_di_IXMLTestSuiteType __fastcall TXMLtestsuites::Insert(const int Index)
{
  return (_di_IXMLTestSuiteType) AddItem(Index);
};

// TXMLTestSuiteType

void __fastcall TXMLTestSuiteType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("testcase"), __classid(TXMLTestCaseType));
  ItemTag = "testcase";
  ItemInterface = __uuidof(IXMLTestCaseType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

System::UnicodeString __fastcall TXMLTestSuiteType::Get_name()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("name")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLTestSuiteType::Set_name(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("name"), Value);
};

int __fastcall TXMLTestSuiteType::Get_tests()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("tests")]->NodeValue.operator int();
};

void __fastcall TXMLTestSuiteType::Set_tests(int Value)
{
  SetAttribute(System::UnicodeString("tests"), Value);
};

int __fastcall TXMLTestSuiteType::Get_failures()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("failures")]->NodeValue.operator int();
};

void __fastcall TXMLTestSuiteType::Set_failures(int Value)
{
  SetAttribute(System::UnicodeString("failures"), Value);
};

int __fastcall TXMLTestSuiteType::Get_errors()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("errors")]->NodeValue.operator int();
};

void __fastcall TXMLTestSuiteType::Set_errors(int Value)
{
  SetAttribute(System::UnicodeString("errors"), Value);
};

int __fastcall TXMLTestSuiteType::Get_disabled()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("disabled")]->NodeValue.operator int();
};

void __fastcall TXMLTestSuiteType::Set_disabled(int Value)
{
  SetAttribute(System::UnicodeString("disabled"), Value);
};

System::UnicodeString __fastcall TXMLTestSuiteType::Get_time()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("time")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLTestSuiteType::Set_time(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("time"), Value);
};

_di_IXMLTestCaseType __fastcall TXMLTestSuiteType::Get_testcase(int Index)
{
  return (_di_IXMLTestCaseType) List->Nodes[Index];
};

_di_IXMLTestCaseType __fastcall TXMLTestSuiteType::Add()
{
  return (_di_IXMLTestCaseType) AddItem(-1);
};

_di_IXMLTestCaseType __fastcall TXMLTestSuiteType::Insert(const int Index)
{
  return (_di_IXMLTestCaseType) AddItem(Index);
};

// TXMLTestCaseType

void __fastcall TXMLTestCaseType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("failure"), __classid(TXMLFailureType));
  ItemTag = "failure";
  ItemInterface = __uuidof(IXMLFailureType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

System::UnicodeString __fastcall TXMLTestCaseType::Get_name()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("name")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLTestCaseType::Set_name(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("name"), Value);
};

System::UnicodeString __fastcall TXMLTestCaseType::Get_status()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("status")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLTestCaseType::Set_status(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("status"), Value);
};

System::UnicodeString __fastcall TXMLTestCaseType::Get_time()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("time")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLTestCaseType::Set_time(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("time"), Value);
};

System::UnicodeString __fastcall TXMLTestCaseType::Get_classname()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("classname")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLTestCaseType::Set_classname(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("classname"), Value);
};

_di_IXMLFailureType __fastcall TXMLTestCaseType::Get_failure(int Index)
{
  return (_di_IXMLFailureType) List->Nodes[Index];
};

_di_IXMLFailureType __fastcall TXMLTestCaseType::Add()
{
  return (_di_IXMLFailureType) AddItem(-1);
};

_di_IXMLFailureType __fastcall TXMLTestCaseType::Insert(const int Index)
{
  return (_di_IXMLFailureType) AddItem(Index);
};

// TXMLFailureType

System::UnicodeString __fastcall TXMLFailureType::Get_message()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("message")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLFailureType::Set_message(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("message"), Value);
};

System::UnicodeString __fastcall TXMLFailureType::Get_type()
{
  return GetAttributeNodes()->Nodes[System::UnicodeString("type")]->NodeValue.operator System::UnicodeString();
};

void __fastcall TXMLFailureType::Set_type(System::UnicodeString Value)
{
  SetAttribute(System::UnicodeString("type"), Value);
};

