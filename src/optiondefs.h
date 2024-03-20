/* vi:set ts=8 sts=4 sw=4 noet:
 *
 * VIM - Vi IMproved	by Bram Moolenaar
 *
 * Do ":help uganda"  in Vim to read copying and usage conditions.
 * Do ":help credits" in Vim to see a list of people who contributed.
 */

/*
 * optiondefs.h: option definitions
 */

/* #if TARGET_OS_IPHONE  */
/* #define DYNAMIC_PYTHON3_DLL "python3_ios.framework/python3_ios" */
/* #endif */

// The options that are local to a window or buffer have "indir" set to one of
// these values.  Special values:
// PV_NONE: global option.
// PV_WIN is added: window-local option
// PV_BUF is added: buffer-local option
// PV_BOTH is added: global option which also has a local value.
#define PV_BOTH 0x1000
#define PV_WIN  0x2000
#define PV_BUF  0x4000
#define PV_MASK 0x0fff
#define OPT_WIN(x)  (idopt_T)(PV_WIN + (int)(x))
#define OPT_BUF(x)  (idopt_T)(PV_BUF + (int)(x))
#define OPT_BOTH(x) (idopt_T)(PV_BOTH + (int)(x))

// Definition of the PV_ values for buffer-local options.
// The BV_ values are defined in option.h.
#define PV_AI		OPT_BUF(BV_AI)
#define PV_AR		OPT_BOTH(OPT_BUF(BV_AR))
#define PV_BKC		OPT_BOTH(OPT_BUF(BV_BKC))
#define PV_BH		OPT_BUF(BV_BH)
#define PV_BT		OPT_BUF(BV_BT)
#ifdef FEAT_QUICKFIX
# define PV_EFM		OPT_BOTH(OPT_BUF(BV_EFM))
# define PV_GP		OPT_BOTH(OPT_BUF(BV_GP))
# define PV_MP		OPT_BOTH(OPT_BUF(BV_MP))
#endif
#define PV_BIN		OPT_BUF(BV_BIN)
#define PV_BL		OPT_BUF(BV_BL)
#define PV_BOMB		OPT_BUF(BV_BOMB)
#define PV_CI		OPT_BUF(BV_CI)
#define PV_CIN		OPT_BUF(BV_CIN)
#define PV_CINK		OPT_BUF(BV_CINK)
#define PV_CINO		OPT_BUF(BV_CINO)
#define PV_CINSD	OPT_BUF(BV_CINSD)
#define PV_CINW		OPT_BUF(BV_CINW)
#define PV_CM		OPT_BOTH(OPT_BUF(BV_CM))
#ifdef FEAT_FOLDING
# define PV_CMS		OPT_BUF(BV_CMS)
#endif
#define PV_COM		OPT_BUF(BV_COM)
#define PV_CPT		OPT_BUF(BV_CPT)
#define PV_DICT		OPT_BOTH(OPT_BUF(BV_DICT))
#define PV_TSR		OPT_BOTH(OPT_BUF(BV_TSR))
#define PV_CSL		OPT_BUF(BV_CSL)
#ifdef FEAT_COMPL_FUNC
# define PV_CFU		OPT_BUF(BV_CFU)
#endif
#ifdef FEAT_FIND_ID
# define PV_DEF		OPT_BOTH(OPT_BUF(BV_DEF))
# define PV_INC		OPT_BOTH(OPT_BUF(BV_INC))
#endif
#define PV_EOF		OPT_BUF(BV_EOF)
#define PV_EOL		OPT_BUF(BV_EOL)
#define PV_FIXEOL	OPT_BUF(BV_FIXEOL)
#define PV_EP		OPT_BOTH(OPT_BUF(BV_EP))
#define PV_ET		OPT_BUF(BV_ET)
#define PV_FENC		OPT_BUF(BV_FENC)
#if defined(FEAT_BEVAL) && defined(FEAT_EVAL)
# define PV_BEXPR	OPT_BOTH(OPT_BUF(BV_BEXPR))
#endif
#define PV_FP		OPT_BOTH(OPT_BUF(BV_FP))
#ifdef FEAT_EVAL
# define PV_FEX		OPT_BUF(BV_FEX)
#endif
#define PV_FF		OPT_BUF(BV_FF)
#define PV_FLP		OPT_BUF(BV_FLP)
#define PV_FO		OPT_BUF(BV_FO)
#define PV_FT		OPT_BUF(BV_FT)
#define PV_IMI		OPT_BUF(BV_IMI)
#define PV_IMS		OPT_BUF(BV_IMS)
#if defined(FEAT_EVAL)
# define PV_INDE	OPT_BUF(BV_INDE)
# define PV_INDK	OPT_BUF(BV_INDK)
#endif
#if defined(FEAT_FIND_ID) && defined(FEAT_EVAL)
# define PV_INEX	OPT_BUF(BV_INEX)
#endif
#define PV_INF		OPT_BUF(BV_INF)
#define PV_ISK		OPT_BUF(BV_ISK)
#ifdef FEAT_CRYPT
# define PV_KEY		OPT_BUF(BV_KEY)
#endif
#ifdef FEAT_KEYMAP
# define PV_KMAP	OPT_BUF(BV_KMAP)
#endif
#define PV_KP		OPT_BOTH(OPT_BUF(BV_KP))
#define PV_LISP		OPT_BUF(BV_LISP)
#define PV_LOP		OPT_BUF(BV_LOP)
#define PV_LW		OPT_BOTH(OPT_BUF(BV_LW))
#define PV_MENC		OPT_BOTH(OPT_BUF(BV_MENC))
#define PV_MA		OPT_BUF(BV_MA)
#define PV_ML		OPT_BUF(BV_ML)
#define PV_MOD		OPT_BUF(BV_MOD)
#define PV_MPS		OPT_BUF(BV_MPS)
#define PV_NF		OPT_BUF(BV_NF)
#ifdef FEAT_COMPL_FUNC
# define PV_OFU		OPT_BUF(BV_OFU)
#endif
#define PV_PATH		OPT_BOTH(OPT_BUF(BV_PATH))
#define PV_PI		OPT_BUF(BV_PI)
#define PV_QE		OPT_BUF(BV_QE)
#define PV_RO		OPT_BUF(BV_RO)
#define PV_SI		OPT_BUF(BV_SI)
#define PV_SN		OPT_BUF(BV_SN)
#ifdef FEAT_SYN_HL
# define PV_SMC		OPT_BUF(BV_SMC)
# define PV_SYN		OPT_BUF(BV_SYN)
#endif
#ifdef FEAT_SPELL
# define PV_SPC		OPT_BUF(BV_SPC)
# define PV_SPF		OPT_BUF(BV_SPF)
# define PV_SPL		OPT_BUF(BV_SPL)
# define PV_SPO		OPT_BUF(BV_SPO)
#endif
#define PV_STS		OPT_BUF(BV_STS)
#define PV_SUA		OPT_BUF(BV_SUA)
#define PV_SW		OPT_BUF(BV_SW)
#define PV_SWF		OPT_BUF(BV_SWF)
#ifdef FEAT_EVAL
# define PV_TFU		OPT_BUF(BV_TFU)
#endif
#ifdef FEAT_COMPL_FUNC
# define PV_TSRFU	OPT_BOTH(OPT_BUF(BV_TSRFU))
#endif
#define PV_TAGS		OPT_BOTH(OPT_BUF(BV_TAGS))
#define PV_TC		OPT_BOTH(OPT_BUF(BV_TC))
#define PV_TS		OPT_BUF(BV_TS)
#define PV_TW		OPT_BUF(BV_TW)
#define PV_TX		OPT_BUF(BV_TX)
#ifdef FEAT_PERSISTENT_UNDO
# define PV_UDF		OPT_BUF(BV_UDF)
#endif
#define PV_WM		OPT_BUF(BV_WM)
#ifdef FEAT_VARTABS
# define PV_VSTS	OPT_BUF(BV_VSTS)
# define PV_VTS		OPT_BUF(BV_VTS)
#endif

// Definition of the PV_ values for window-local options.
// The WV_ values are defined in option.h.
#define PV_LIST		OPT_WIN(WV_LIST)
#ifdef FEAT_ARABIC
# define PV_ARAB	OPT_WIN(WV_ARAB)
#endif
#ifdef FEAT_LINEBREAK
# define PV_BRI		OPT_WIN(WV_BRI)
# define PV_BRIOPT	OPT_WIN(WV_BRIOPT)
#endif
# define PV_WCR		OPT_WIN(WV_WCR)
#ifdef FEAT_DIFF
# define PV_DIFF	OPT_WIN(WV_DIFF)
#endif
#ifdef FEAT_FOLDING
# define PV_FDC		OPT_WIN(WV_FDC)
# define PV_FEN		OPT_WIN(WV_FEN)
# define PV_FDI		OPT_WIN(WV_FDI)
# define PV_FDL		OPT_WIN(WV_FDL)
# define PV_FDM		OPT_WIN(WV_FDM)
# define PV_FML		OPT_WIN(WV_FML)
# define PV_FDN		OPT_WIN(WV_FDN)
# ifdef FEAT_EVAL
#  define PV_FDE	OPT_WIN(WV_FDE)
#  define PV_FDT	OPT_WIN(WV_FDT)
# endif
# define PV_FMR		OPT_WIN(WV_FMR)
#endif
#ifdef FEAT_LINEBREAK
# define PV_LBR		OPT_WIN(WV_LBR)
#endif
#define PV_LCS		OPT_BOTH(OPT_WIN(WV_LCS))
#define PV_FCS		OPT_BOTH(OPT_WIN(WV_FCS))
#define PV_NU		OPT_WIN(WV_NU)
#define PV_RNU		OPT_WIN(WV_RNU)
#define PV_VE		OPT_BOTH(OPT_WIN(WV_VE))
#ifdef FEAT_LINEBREAK
# define PV_NUW		OPT_WIN(WV_NUW)
#endif
#if defined(FEAT_QUICKFIX)
# define PV_PVW		OPT_WIN(WV_PVW)
#endif
#ifdef FEAT_RIGHTLEFT
# define PV_RL		OPT_WIN(WV_RL)
# define PV_RLC		OPT_WIN(WV_RLC)
#endif
#define PV_SCBIND	OPT_WIN(WV_SCBIND)
#define PV_SCROLL	OPT_WIN(WV_SCROLL)
#define PV_SMS		OPT_WIN(WV_SMS)
#define PV_SISO		OPT_BOTH(OPT_WIN(WV_SISO))
#define PV_SO		OPT_BOTH(OPT_WIN(WV_SO))
#ifdef FEAT_SPELL
# define PV_SPELL	OPT_WIN(WV_SPELL)
#endif
#ifdef FEAT_SYN_HL
# define PV_CUC		OPT_WIN(WV_CUC)
# define PV_CUL		OPT_WIN(WV_CUL)
# define PV_CULOPT	OPT_WIN(WV_CULOPT)
# define PV_CC		OPT_WIN(WV_CC)
#endif
#ifdef FEAT_LINEBREAK
# define PV_SBR		OPT_BOTH(OPT_WIN(WV_SBR))
#endif
#ifdef FEAT_STL_OPT
# define PV_STL		OPT_BOTH(OPT_WIN(WV_STL))
#endif
#define PV_UL		OPT_BOTH(OPT_BUF(BV_UL))
# define PV_WFB		OPT_WIN(WV_WFB)
# define PV_WFH		OPT_WIN(WV_WFH)
# define PV_WFW		OPT_WIN(WV_WFW)
#define PV_WRAP		OPT_WIN(WV_WRAP)
#define PV_CRBIND	OPT_WIN(WV_CRBIND)
#ifdef FEAT_CONCEAL
# define PV_COCU	OPT_WIN(WV_COCU)
# define PV_COLE	OPT_WIN(WV_COLE)
#endif
#ifdef FEAT_TERMINAL
# define PV_TWK		OPT_WIN(WV_TWK)
# define PV_TWS		OPT_WIN(WV_TWS)
# define PV_TWSL	OPT_BUF(BV_TWSL)
#endif
#ifdef FEAT_SIGNS
# define PV_SCL		OPT_WIN(WV_SCL)
#endif

// WV_ and BV_ values get typecasted to this for the "indir" field
typedef enum
{
    PV_NONE = 0,
    PV_MAXVAL = 0xffff    // to avoid warnings for value out of range
} idopt_T;

// Options local to a window have a value local to a buffer and global to all
// buffers.  Indicate this by setting "var" to VAR_WIN.
#define VAR_WIN ((char_u *)-1)

// Saved values for when 'bin' is set.
static __thread int	p_et_nobin;
static __thread int	p_ml_nobin;
static __thread long	p_tw_nobin;
static __thread long	p_wm_nobin;

// Saved values for when 'paste' is set
static __thread int	p_ai_nopaste;
static __thread int	p_et_nopaste;
static __thread long	p_sts_nopaste;
static __thread long	p_tw_nopaste;
static __thread long	p_wm_nopaste;
#ifdef FEAT_VARTABS
static __thread char_u	*p_vsts_nopaste;
#endif

struct vimoption
{
    char	*fullname;	// full option name
    char	*shortname;	// permissible abbreviation
    long_u	flags;		// see in option.h
    char_u	*var;		// global option: pointer to variable;
				// window-local option: VAR_WIN;
				// buffer-local option: global value
    idopt_T	indir;		// global option: PV_NONE;
				// local option: indirect option index
    // callback function to invoke after an option is modified to validate and
    // apply the new value.
    opt_did_set_cb_T	opt_did_set_cb;

    // callback function to invoke when expanding possible values on the
    // cmdline. Only useful for string options.
    opt_expand_cb_T	opt_expand_cb;

    char_u	*def_val[2];	// default values for variable (vi and vim)
#ifdef FEAT_EVAL
    sctx_T	script_ctx;	// script context where the option was last set
# define SCTX_INIT , {0, 0, 0, 1}
#else
# define SCTX_INIT
#endif
};

EXTERN struct vimoption (*options_ptr)[];
EXTERN int OPTION_COUNT;
void set_init_default_options();

#define VI_DEFAULT  0	    // def_val[VI_DEFAULT] is Vi default value
#define VIM_DEFAULT 1	    // def_val[VIM_DEFAULT] is Vim default value

#define ISK_LATIN1  (char_u *)"@,48-57,_,192-255"

// 'isprint' for latin1 is also used for MS-Windows cp1252, where 0x80 is used
// for the currency sign.
#if defined(MSWIN)
# define ISP_LATIN1 (char_u *)"@,~-255"
#else
# define ISP_LATIN1 (char_u *)"@,161-255"
#endif

# define HIGHLIGHT_INIT "8:SpecialKey,~:EndOfBuffer,@:NonText,d:Directory,e:ErrorMsg,i:IncSearch,l:Search,y:CurSearch,m:MoreMsg,M:ModeMsg,n:LineNr,a:LineNrAbove,b:LineNrBelow,N:CursorLineNr,G:CursorLineSign,O:CursorLineFold,r:Question,s:StatusLine,S:StatusLineNC,c:VertSplit,t:Title,v:Visual,V:VisualNOS,w:WarningMsg,W:WildMenu,f:Folded,F:FoldColumn,A:DiffAdd,C:DiffChange,D:DiffDelete,T:DiffText,>:SignColumn,-:Conceal,B:SpellBad,P:SpellCap,R:SpellRare,L:SpellLocal,+:Pmenu,=:PmenuSel,[:PmenuKind,]:PmenuKindSel,{:PmenuExtra,}:PmenuExtraSel,x:PmenuSbar,X:PmenuThumb,*:TabLine,#:TabLineSel,_:TabLineFill,!:CursorColumn,.:CursorLine,o:ColorColumn,q:QuickFixLine,z:StatusLineTerm,Z:StatusLineTermNC"

// Default python version for pyx* commands
#if defined(FEAT_PYTHON) && defined(FEAT_PYTHON3)
# define DEFAULT_PYTHON_VER	0
#elif defined(FEAT_PYTHON3)
# define DEFAULT_PYTHON_VER	3
#elif defined(FEAT_PYTHON)
# define DEFAULT_PYTHON_VER	2
#else
# define DEFAULT_PYTHON_VER	0
#endif

// used for 'cinkeys' and 'indentkeys'
#define INDENTKEYS_DEFAULT (char_u *)"0{,0},0),0],:,0#,!^F,o,O,e"

//#define OPTION_COUNT ARRAY_LENGTH(options)

// The following is needed to make the gen_opt_test.vim script work.
// {"
