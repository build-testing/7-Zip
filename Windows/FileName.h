// Windows/FileName.h

#pragma once

#ifndef __WINDOWS_FILENAME_H
#define __WINDOWS_FILENAME_H

#include "../Common/String.h"

namespace NWindows {
namespace NFile {
namespace NName {

const TCHAR kDirDelimiter = '\\';
const TCHAR kAnyStringWildcard = '*';

void NormalizeDirPathPrefix(CSysString &dirPath); // ensures that it ended with '\\'

namespace NPathType
{
  enum EEnum
  {
    kLocal,
    kUNC
  };
  EEnum GetPathType(const UString &path);
}

struct CParsedPath
{
  UString Prefix; // Disk or UNC with slash
  UStringVector PathParts;
  void ParsePath(const UString &path);
  UString MergePath() const;
};

void SplitNameToPureNameAndExtension(const CSysString &fullName, 
    CSysString &pureName, CSysString &extensionDelimiter, CSysString &extension); 

}}}

#endif