#ifndef CHARINFO_INCLUDE
#define CHARINFO_INCLUDE

class CharInfo // : ICharInfo
{

public:
    void init(int cid, int gindex) { m_char = cid; m_before = m_after = gindex; }
    void update(int offset, int slot_offset) { m_before += offset; m_after += offset; } 

protected:
    int m_char;     // Unicode character in character stream
    int m_before;   // slot id of glyph that cursor before this char is before
    int m_after;    // slot id of glyph that cursor after this char is after
};

#endif // CHARINFO_INCLUDE

