#pragma once

#include "Main.h"

#include "Pass.h"

namespace org { namespace sil { namespace graphite { namespace v2 {

class GrFace;
class VMScratch;
class GrSegment;

class Pseudo
{
public:
    uint32 uid;
    uint32 gid;
    CLASS_NEW_DELETE
};

class Silf
{
public:
    Silf() throw();
    ~Silf() throw();
    
    bool readGraphite(void *pSilf, size_t lSilf, int numGlyphs, uint32 version);
    void runGraphite(GrSegment *seg, const GrFace *face, VMScratch *vms) const;
    uint16 findClassIndex(uint16 cid, uint16 gid) const;
    uint16 getClassGlyph(uint16 cid, int index) const;
    uint16 findPseudo(uint32 uid) const;
    uint8 numUser() const { return m_aUser; }
    uint8 aPseudo() const { return m_aPseudo; }
    uint8 aBreak() const { return m_aBreak; }

    CLASS_NEW_DELETE

private:
    size_t readClassMap(void *pClass, size_t lClass, int numGlyphs);

    Pass          * m_passes;
    Pseudo        * m_pseudos;
    uint16        * m_classOffsets, 
                  * m_classData;
    size_t          m_numPasses;
    uint8           m_sPass, m_pPass, m_jPass, m_bPass,
                    m_flags;

    uint8   m_aPseudo, m_aBreak, m_aUser, 
            m_iMaxComp;
    uint16  m_aLig,
            m_numPseudo,
            m_nClass,
            m_nLinear;
    
    void releaseBuffers() throw();
    
private:			//defensive
    Silf(const Silf&);
    Silf& operator=(const Silf&);
};

}}}} // namespace
