#ifndef LIONHEART_H
#define LIONHEART_H
#include "unit.h"

#include "dww.h"
#include "acs.h"
#include "acy.h"
#include "als.h"
#include "ama.h"
#include "amb.h"
#include "ask.h"
#include "bhg.h"
#include "bob.h"
#include "cbg.h"
#include "cdj.h"
#include "cdv.h"
#include "cfl.h"
#include "cgm.h"
#include "cjs.h"
#include "cmr.h"
#include "crr.h"
#include "dah.h"
#include "ewh.h"
#include "fts.h"
#include "gbm.h"
#include "gdo.h"
#include "ggv.h"
#include "gwb.h"
#include "jcl.h"
#include "jcs.h"
#include "jgh.h"
#include "jkc.h"
#include "kbl.h"
#include "kp7.h"
#include "lif.h"
#include "mav.h"
#include "mmk.h"
#include "mpt.h"
#include "nmn.h"
#include "oku.h"
#include "pja.h"
#include "pwr.h"
#include "rac.h"
#include "rhw.h"
#include "rkt.h"
#include "sam.h"
#include "ski.h"
#include "sol.h"
#include "swc.h"
#include "tah.h"
#include "trj.h"
#include "trd.h"
#include "wig.h"
#include "zjt.h"

#include "lionheart2.h"

using namespace std;

struct Box{
	int minr;
	int maxr;
	int minc;
	int maxc;
};

bool noPlay[NUMTLAS]={
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,0
};

static const string tlalist[NUMTLAS]={
"dww",
"acs",
"acy",
"als",
"ama",
"amb",
"ask",
"bhg",
"bob",
"cbg",
"cdj",
"cdv",
"cfl",
"cgm",
"cjs",
"cmr",
"crr",
"dah",
"ewh",
"fts",
"gbm",
"gdo",
"ggv",
"gwb",
"jcl",
"jcs",
"jgh",
"jkc",
"kbl",
"kp7",
"lif",
"mav",
"mmk",
"mpt",
"nmn",
"oku",
"pja",
"pwr",
"rac",
"rhw",
"rkt",
"sam",
"ski",
"sol",
"swc",
"tah",
"trj",
"trd",
"wig",
"zjt",
};
#endif
