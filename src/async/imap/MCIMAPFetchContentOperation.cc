//
//  IMAPFetchContentOperation.cc
//  mailcore2
//
//  Created by DINH Viêt Hoà on 1/12/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#include "MCIMAPFetchContentOperation.h"

#include "MCIMAPSession.h"
#include "MCIMAPAsyncSession.h"

using namespace mailcore;

IMAPFetchContentOperation::IMAPFetchContentOperation()
{
    mFolder = NULL;
    mUid = 0;
    mPartID = NULL;
    mEncoding = Encoding7Bit;
    mData = NULL;
}

IMAPFetchContentOperation::~IMAPFetchContentOperation()
{
    MC_SAFE_RELEASE(mFolder);
    MC_SAFE_RELEASE(mPartID);
    MC_SAFE_RELEASE(mData);
}

void IMAPFetchContentOperation::setFolder(String * folder)
{
    MC_SAFE_REPLACE_COPY(String, mFolder, folder);
}

String * IMAPFetchContentOperation::folder()
{
    return mFolder;
}

void IMAPFetchContentOperation::setUid(uint32_t uid)
{
    mUid = uid;
}

uint32_t IMAPFetchContentOperation::uid()
{
    return mUid;
}

void IMAPFetchContentOperation::setPartID(String * partID)
{
    MC_SAFE_REPLACE_COPY(String, mPartID, partID);
}

String * IMAPFetchContentOperation::partID()
{
    return mPartID;
}

void IMAPFetchContentOperation::setEncoding(Encoding encoding)
{
    mEncoding = encoding;
}

Encoding IMAPFetchContentOperation::encoding()
{
    return mEncoding;
}

Data * IMAPFetchContentOperation::data()
{
    return mData;
}

void IMAPFetchContentOperation::main()
{
    ErrorCode error;
    if (mPartID != NULL) {
        mData = session()->session()->fetchMessageAttachmentByUID(mFolder, mUid, mPartID, mEncoding, this, &error);
    }
    else {
        mData = session()->session()->fetchMessageByUID(mFolder, mUid, this, &error);
    }
    MC_SAFE_RETAIN(mData);
    setError(error);
}

