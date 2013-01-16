//
//  IMAPIdentityOperation.h
//  mailcore2
//
//  Created by DINH Viêt Hoà on 1/12/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef __mailcore2__IMAPIdentityOperation__
#define __mailcore2__IMAPIdentityOperation__

#include <mailcore/MCIMAPOperation.h>

namespace mailcore {
    
    class IMAPIdentityOperation : public IMAPOperation {
    private:
        String * mVendor;
        String * mName;
        String * mVersion;
        HashMap * mServerIdentity;
        
    public:
        IMAPIdentityOperation();
        virtual ~IMAPIdentityOperation();
        
        virtual void setVendor(String * vendor);
        virtual String * vendor();
        
        virtual void setName(String * name);
        virtual String * name();
        
        virtual void setVersion(String * version);
        virtual String * version();
        
        virtual HashMap * serverIdentity();
        
        virtual void main();
    };
}

#endif /* defined(__mailcore2__IMAPIdentityOperation__) */
