
#include "cbase.h"
#include "tier0/dbg.h"
#include "memdbgon.h" // always the LAST include

class CWTicker : public CBaseEntity
{
public:
    DECLARE_CLASS( CWTicker, CBaseEntity );
    DECLARE_DATADESC();

    void Spawn() override;
    void TickThink();

private:
    int m_iCount;
};

LINK_ENTITY_TO_CLASS( w_ticker, CWTicker );

BEGIN_DATADESC( CWTicker )
    DEFINE_FIELD( m_iCount, FIELD_INTEGER ),
    DEFINE_THINKFUNC( TickThink ),
END_DATADESC()

void CWTicker::Spawn()
{
    BaseClass::Spawn();
    m_iCount = 0;
    SetThink( &CWTicker::TickThink );
    SetNextThink( gpGlobals->curtime + 1.0f );
}

void CWTicker::TickThink()
{
    m_iCount++;
    Msg( "w_ticker: tick %d\n", m_iCount );
    SetNextThink( gpGlobals->curtime + 1.0f );
}