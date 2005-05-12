/*	$OpenBSD: ukbdmap.c,v 1.18 2005/05/12 09:28:37 miod Exp $	*/

/*
 * THIS FILE IS AUTOMAGICALLY GENERATED.  DO NOT EDIT.
 *
 * generated by:
 *	OpenBSD: makemap.awk,v 1.2 2005/05/12 09:28:21 miod Exp 
 * generated from:
 */
/*	OpenBSD: wskbdmap_mfii.c,v 1.30 2005/05/09 05:08:57 miod Exp  */
/*	$NetBSD: wskbdmap_mfii.c,v 1.15 2000/05/19 16:40:04 drochner Exp $	*/

/*
 * PLEASE DO NOT FORGET TO REGEN
 *	sys/arch/hppa/gsc/gsckbdmap.c
 *	sys/dev/usb/ukbdmap.c
 * AFTER ANY CHANGES TO THIS FILE!
 */

/*-
 * Copyright (c) 1997 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Juergen Hannken-Illjes.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the NetBSD
 *	Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/types.h>
#include <dev/wscons/wsksymdef.h>
#include <dev/wscons/wsksymvar.h>
#include <dev/usb/usb_port.h>

#define KC(n) KS_KEYCODE(n)

static const keysym_t ukbd_keydesc_us[] = {
/*  pos      command		normal		shifted */
    KC(4),	KS_a,
    KC(5),	KS_b,
    KC(6),	KS_c,
    KC(7),	KS_d,
    KC(8),	KS_e,
    KC(9),	KS_f,
    KC(10),	KS_g,
    KC(11),	KS_h,
    KC(12),	KS_i,
    KC(13),	KS_j,
    KC(14),	KS_k,
    KC(15),	KS_l,
    KC(16),	KS_m,
    KC(17),	KS_n,
    KC(18),	KS_o,
    KC(19),	KS_p,
    KC(20),	KS_q,
    KC(21),	KS_r,
    KC(22),	KS_s,
    KC(23),	KS_t,
    KC(24),	KS_u,
    KC(25),	KS_v,
    KC(26),	KS_w,
    KC(27),	KS_x,
    KC(28),	KS_y,
    KC(29),	KS_z,
    KC(30),	KS_1,	KS_exclam,
    KC(31),	KS_2,	KS_at,
    KC(32),	KS_3,	KS_numbersign,
    KC(33),	KS_4,	KS_dollar,
    KC(34),	KS_5,	KS_percent,
    KC(35),	KS_6,	KS_asciicircum,
    KC(36),	KS_7,	KS_ampersand,
    KC(37),	KS_8,	KS_asterisk,
    KC(38),	KS_9,	KS_parenleft,
    KC(39),	KS_0,	KS_parenright,
    KC(40),	KS_Return,
    KC(41),	KS_Cmd_Debugger,	KS_Escape,
    KC(42),	KS_Cmd_ResetEmul,	KS_Delete,
    KC(43),	KS_Tab,
    KC(44),	KS_space,
    KC(45),	KS_minus,	KS_underscore,
    KC(46),	KS_equal,	KS_plus,
    KC(47),	KS_bracketleft,	KS_braceleft,
    KC(48),	KS_bracketright,	KS_braceright,
    KC(50),	KS_backslash,	KS_bar,
    KC(51),	KS_semicolon,	KS_colon,
    KC(52),	KS_apostrophe,	KS_quotedbl,
    KC(53),	KS_grave,	KS_asciitilde,
    KC(54),	KS_comma,	KS_less,
    KC(55),	KS_period,	KS_greater,
    KC(56),	KS_slash,	KS_question,
    KC(57),	KS_Caps_Lock,
    KC(58),	KS_Cmd_Screen0,	KS_f1,
    KC(59),	KS_Cmd_Screen1,	KS_f2,
    KC(60),	KS_Cmd_Screen2,	KS_f3,
    KC(61),	KS_Cmd_Screen3,	KS_f4,
    KC(62),	KS_Cmd_Screen4,	KS_f5,
    KC(63),	KS_Cmd_Screen5,	KS_f6,
    KC(64),	KS_Cmd_Screen6,	KS_f7,
    KC(65),	KS_Cmd_Screen7,	KS_f8,
    KC(66),	KS_Cmd_Screen8,	KS_f9,
    KC(67),	KS_Cmd_Screen9,	KS_f10,
    KC(68),	KS_Cmd_Screen10,	KS_f11,
    KC(69),	KS_Cmd_Screen11,	KS_f12,
    KC(70),	KS_Print_Screen,
    KC(71),	KS_Hold_Screen,
    KC(72),	KS_Pause,	/*	Break	*/
    KC(73),	KS_Insert,
    KC(74),	KS_Home,
    KC(75),	KS_Cmd_ScrollBack,	KS_Prior,
    KC(76),	KS_Cmd_ResetEmul,	KS_Delete,
    KC(77),	KS_End,
    KC(78),	KS_Cmd_ScrollFwd,	KS_Next,
    KC(79),	KS_Right,
    KC(80),	KS_Left,
    KC(81),	KS_Down,
    KC(82),	KS_Up,
    KC(83),	KS_Num_Lock,
    KC(84),	KS_KP_Divide,
    KC(85),	KS_KP_Multiply,
    KC(86),	KS_KP_Subtract,
    KC(87),	KS_KP_Add,
    KC(88),	KS_KP_Enter,
    KC(89),	KS_KP_End,	KS_KP_1,
    KC(90),	KS_KP_Down,	KS_KP_2,
    KC(91),	KS_KP_Next,	KS_KP_3,
    KC(92),	KS_KP_Left,	KS_KP_4,
    KC(93),	KS_KP_Begin,	KS_KP_5,
    KC(94),	KS_KP_Right,	KS_KP_6,
    KC(95),	KS_KP_Home,	KS_KP_7,
    KC(96),	KS_KP_Up,	KS_KP_8,
    KC(97),	KS_KP_Prior,	KS_KP_9,
    KC(98),	KS_KP_Insert,	KS_KP_0,
    KC(99),	KS_Cmd_KbdReset,	KS_KP_Delete,
    KC(101),	KS_Menu,
    KC(224),	KS_Cmd1,	KS_Control_L,
    KC(225),	KS_Shift_L,
    KC(226),	KS_Cmd2,	KS_Alt_L,
    KC(227),	KS_Meta_L,
    KC(228),	KS_Cmd1,	KS_Control_R,
    KC(229),	KS_Shift_R,
    KC(230),	KS_Cmd2,	KS_Alt_R,	KS_Multi_key,
    KC(231),	KS_Meta_R,
};

#if !defined(SMALL_KERNEL) || !defined(__alpha__)

static const keysym_t ukbd_keydesc_de[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(16),	KS_m,	KS_M,	KS_mu,
    KC(20),	KS_q,	KS_Q,	KS_at,
    KC(28),	KS_z,
    KC(29),	KS_y,
    KC(31),	KS_2,	KS_quotedbl,	KS_twosuperior,
    KC(32),	KS_3,	KS_section,	KS_threesuperior,
    KC(35),	KS_6,	KS_ampersand,
    KC(36),	KS_7,	KS_slash,	KS_braceleft,
    KC(37),	KS_8,	KS_parenleft,	KS_bracketleft,
    KC(38),	KS_9,	KS_parenright,	KS_bracketright,
    KC(39),	KS_0,	KS_equal,	KS_braceright,
    KC(45),	KS_ssharp,	KS_question,	KS_backslash,
    KC(46),	KS_dead_acute,	KS_dead_grave,
    KC(47),	KS_udiaeresis,
    KC(48),	KS_plus,	KS_asterisk,	KS_dead_tilde,
    KC(50),	KS_numbersign,	KS_apostrophe,
    KC(51),	KS_odiaeresis,
    KC(52),	KS_adiaeresis,
    KC(53),	KS_dead_circumflex,KS_dead_abovering,
    KC(54),	KS_comma,	KS_semicolon,
    KC(55),	KS_period,	KS_colon,
    KC(56),	KS_minus,	KS_underscore,
    KC(100),	KS_less,	KS_greater,	KS_bar,	KS_brokenbar,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_de_nodead[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(46),	KS_apostrophe,	KS_grave,
    KC(48),	KS_plus,	KS_asterisk,	KS_asciitilde,
    KC(53),	KS_asciicircum,	KS_degree,
};

static const keysym_t ukbd_keydesc_dk[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(31),	KS_2,	KS_quotedbl,	KS_at,
    KC(32),	KS_3,	KS_numbersign,	KS_sterling,
    KC(33),	KS_4,	KS_currency,	KS_dollar,
    KC(35),	KS_6,	KS_ampersand,
    KC(36),	KS_7,	KS_slash,	KS_braceleft,
    KC(37),	KS_8,	KS_parenleft,	KS_bracketleft,
    KC(38),	KS_9,	KS_parenright,	KS_bracketright,
    KC(39),	KS_0,	KS_equal,	KS_braceright,
    KC(45),	KS_plus,	KS_question,
    KC(46),	KS_dead_acute,	KS_dead_grave,	KS_bar,
    KC(47),	KS_aring,
    KC(48),	KS_dead_diaeresis,	KS_dead_circumflex,	KS_dead_tilde,
    KC(50),	KS_apostrophe,	KS_asterisk,
    KC(51),	KS_ae,
    KC(52),	KS_oslash,
    KC(53),	KS_onehalf,	KS_paragraph,
    KC(54),	KS_comma,	KS_semicolon,
    KC(55),	KS_period,	KS_colon,
    KC(56),	KS_minus,	KS_underscore,
    KC(100),	KS_less,	KS_greater,	KS_backslash,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_dk_nodead[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(46),	KS_apostrophe,	KS_grave,	KS_bar,
    KC(48),	KS_diaeresis,	KS_asciicircum,	KS_asciitilde,
};

static const keysym_t ukbd_keydesc_sv[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(45),	KS_plus,	KS_question,	KS_backslash,
    KC(48),	KS_dead_diaeresis,	KS_dead_circumflex,	KS_dead_tilde,
    KC(51),	KS_odiaeresis,
    KC(52),	KS_adiaeresis,
    KC(53),	KS_section,	KS_onehalf,
    KC(100),	KS_less,	KS_greater,	KS_bar,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_sv_nodead[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(46),	KS_apostrophe,	KS_grave,	KS_bar,
    KC(48),	KS_diaeresis,	KS_asciicircum,	KS_asciitilde,
};

static const keysym_t ukbd_keydesc_no[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(46),	KS_backslash,	KS_dead_grave,	KS_dead_acute,
    KC(48),	KS_dead_diaeresis,	KS_dead_circumflex,	KS_dead_tilde,
    KC(51),	KS_oslash,
    KC(52),	KS_ae,
    KC(53),	KS_bar,	KS_paragraph,
    KC(100),	KS_less,	KS_greater,
};

static const keysym_t ukbd_keydesc_no_nodead[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(46),	KS_backslash,	KS_grave,	KS_acute,
    KC(48),	KS_diaeresis,	KS_asciicircum,	KS_asciitilde,
};

static const keysym_t ukbd_keydesc_fr[] = {
/*  pos	     normal		shifted		altgr		shift-altgr */
    KC(4),	KS_q,
    KC(16),	KS_comma,	KS_question,
    KC(20),	KS_a,
    KC(26),	KS_z,
    KC(29),	KS_w,
    KC(30),	KS_ampersand,	KS_1,
    KC(31),	KS_eacute,	KS_2,	KS_asciitilde,
    KC(32),	KS_quotedbl,	KS_3,	KS_numbersign,
    KC(33),	KS_apostrophe,	KS_4,	KS_braceleft,
    KC(34),	KS_parenleft,	KS_5,	KS_bracketleft,
    KC(35),	KS_minus,	KS_6,	KS_bar,
    KC(36),	KS_egrave,	KS_7,	KS_grave,
    KC(37),	KS_underscore,	KS_8,	KS_backslash,
    KC(38),	KS_ccedilla,	KS_9,	KS_asciicircum,
    KC(39),	KS_agrave,	KS_0,	KS_at,
    KC(45),	KS_parenright,	KS_degree,	KS_bracketright,
    KC(46),	KS_equal,	KS_plus,	KS_braceright,
    KC(47),	KS_dead_circumflex,	KS_dead_diaeresis,
    KC(48),	KS_dollar,	KS_sterling,	KS_currency,
    KC(50),	KS_asterisk,	KS_mu,
    KC(51),	KS_m,
    KC(52),	KS_ugrave,	KS_percent,
    KC(53),	KS_twosuperior,
    KC(54),	KS_semicolon,	KS_period,
    KC(55),	KS_colon,	KS_slash,
    KC(56),	KS_exclam,	KS_section,
    KC(100),	KS_less,	KS_greater,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_it[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(31),	KS_2,	KS_quotedbl,	KS_twosuperior,
    KC(32),	KS_3,	KS_sterling,	KS_threesuperior,
    KC(34),	KS_5,	KS_percent,
    KC(35),	KS_6,	KS_ampersand,
    KC(36),	KS_7,	KS_slash,
    KC(37),	KS_8,	KS_parenleft,
    KC(38),	KS_9,	KS_parenright,
    KC(39),	KS_0,	KS_equal,
    KC(45),	KS_apostrophe,	KS_question,
    KC(46),	KS_igrave,	KS_asciicircum,
    KC(47),	KS_egrave,	KS_eacute,	KS_braceleft,	KS_bracketleft,
    KC(48),	KS_plus,	KS_asterisk,	KS_braceright,	KS_bracketright,
    KC(50),	KS_ugrave,	KS_section,
    KC(51),	KS_ograve,	KS_Ccedilla,	KS_at,
    KC(52),	KS_agrave,	KS_degree,	KS_numbersign,
    KC(53),	KS_backslash,	KS_bar,
    KC(54),	KS_comma,	KS_semicolon,
    KC(55),	KS_period,	KS_colon,
    KC(56),	KS_minus,	KS_underscore,
    KC(100),	KS_less,	KS_greater,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_uk[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(30),	KS_1,	KS_exclam,	KS_plusminus,	KS_exclamdown,
    KC(31),	KS_2,	KS_quotedbl,	KS_twosuperior,	KS_cent,
    KC(32),	KS_3,	KS_sterling,	KS_threesuperior,
    KC(33),	KS_4,	KS_dollar,	KS_acute,	KS_currency,
    KC(34),	KS_5,	KS_percent,	KS_mu,	KS_yen,
    KC(35),	KS_6,	KS_asciicircum,	KS_paragraph,
    KC(36),	KS_7,	KS_ampersand,	KS_periodcentered,	KS_brokenbar,
    KC(37),	KS_8,	KS_asterisk,	KS_cedilla,	KS_ordfeminine,
    KC(38),	KS_9,	KS_parenleft,	KS_onesuperior,	KS_diaeresis,
    KC(39),	KS_0,	KS_parenright,	KS_masculine,	KS_copyright,
    KC(45),	KS_minus,	KS_underscore,	KS_hyphen,	KS_ssharp,
    KC(46),	KS_equal,	KS_plus,	KS_onehalf,	KS_guillemotleft,
    KC(50),	KS_numbersign,	KS_asciitilde,	KS_sterling,	KS_thorn,
    KC(52),	KS_apostrophe,	KS_at,	KS_section,	KS_Agrave,
    KC(53),	KS_grave,	KS_grave,	KS_agrave,	KS_agrave,
    KC(100),	KS_backslash,	KS_bar,	KS_Udiaeresis,
};

static const keysym_t ukbd_keydesc_jp[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(31),	KS_2,	KS_quotedbl,
    KC(35),	KS_6,	KS_ampersand,
    KC(36),	KS_7,	KS_apostrophe,
    KC(37),	KS_8,	KS_parenleft,
    KC(38),	KS_9,	KS_parenright,
    KC(39),	KS_0,
    KC(45),	KS_minus,	KS_equal,
    KC(46),	KS_asciicircum,	KS_asciitilde,
    KC(47),	KS_at,	KS_grave,
    KC(48),	KS_bracketleft,	KS_braceleft,
    KC(50),	KS_bracketright,	KS_braceright,
    KC(51),	KS_semicolon,	KS_plus,
    KC(52),	KS_colon,	KS_asterisk,
    KC(53),	KS_Zenkaku_Hankaku,	/*	replace	grave/tilde	*/
    KC(135),	KS_Hiragana_Katakana,
    KC(136),	KS_backslash,	KS_underscore,
    KC(137),	KS_Henkan,
    KC(138),	KS_Muhenkan,
    KC(139),	KS_backslash,	KS_bar,
};

static const keysym_t ukbd_keydesc_es[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(30),	KS_1,	KS_exclam,	KS_bar,
    KC(31),	KS_2,	KS_quotedbl,	KS_at,
    KC(32),	KS_3,	KS_periodcentered,	KS_numbersign,
    KC(33),	KS_4,	KS_dollar,	KS_asciitilde,
    KC(35),	KS_6,	KS_ampersand,
    KC(36),	KS_7,	KS_slash,
    KC(37),	KS_8,	KS_parenleft,
    KC(38),	KS_9,	KS_parenright,
    KC(39),	KS_0,	KS_equal,
    KC(45),	KS_apostrophe,	KS_question,
    KC(46),	KS_exclamdown,	KS_questiondown,
    KC(47),	KS_dead_grave,	KS_dead_circumflex,	KS_bracketleft,
    KC(48),	KS_plus,	KS_asterisk,	KS_bracketright,
    KC(50),	KS_ccedilla,	KS_Ccedilla,	KS_braceright,
    KC(51),	KS_ntilde,
    KC(52),	KS_dead_acute,	KS_dead_diaeresis,	KS_braceleft,
    KC(53),	KS_degree,	KS_ordfeminine,	KS_backslash,
    KC(54),	KS_comma,	KS_semicolon,
    KC(55),	KS_period,	KS_colon,
    KC(56),	KS_minus,	KS_underscore,
    KC(100),	KS_less,	KS_greater,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_lt[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(8),	KS_e,	KS_E,	KS_currency,
    KC(9),	KS_L7_scaron,	KS_L7_Scaron,
    KC(20),	KS_L7_aogonek,	KS_L7_Aogonek,
    KC(26),	KS_L7_zcaron,	KS_L7_Zcaron,
    KC(27),	KS_L7_umacron,	KS_L7_Umacron,
    KC(30),	KS_exclam,	KS_1,	KS_at,
    KC(31),	KS_minus,	KS_2,	KS_underscore,
    KC(32),	KS_slash,	KS_3,	KS_numbersign,
    KC(33),	KS_semicolon,	KS_4,	KS_dollar,
    KC(34),	KS_colon,	KS_5,	KS_paragraph,
    KC(35),	KS_comma,	KS_6,	KS_asciicircum,
    KC(36),	KS_period,	KS_7,	KS_ampersand,
    KC(37),	KS_equal,	KS_8,	KS_asterisk,
    KC(38),	KS_bracketleft,	KS_9,	KS_parenleft,
    KC(39),	KS_bracketright,	KS_0,	KS_parenright,
    KC(44),	KS_space,	KS_space,	KS_nobreakspace,
    KC(45),	KS_question,	KS_plus,	KS_apostrophe,
    KC(46),	KS_x,	KS_X,	KS_percent,
    KC(47),	KS_L7_iogonek,	KS_L7_Iogonek,	KS_braceleft,
    KC(48),	KS_w,	KS_W,	KS_braceright,
    KC(50),	KS_q,	KS_Q,	KS_bar,
    KC(51),	KS_L7_uogonek,	KS_L7_Uogonek,
    KC(52),	KS_L7_edot,	KS_L7_Edot,	KS_quotedbl,
    KC(53),	KS_grave,	KS_asciitilde,
    KC(54),	KS_L7_ccaron,	KS_L7_Ccaron,	KS_L7_dbllow9quot,
    KC(55),	KS_f,	KS_F,	KS_L7_leftdblquot,
    KC(56),	KS_L7_eogonek,	KS_L7_Eogonek,	KS_backslash,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_be[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(4),	KS_q,
    KC(16),	KS_comma,	KS_question,
    KC(20),	KS_a,
    KC(26),	KS_z,
    KC(29),	KS_w,
    KC(30),	KS_ampersand,	KS_1,	KS_bar,
    KC(31),	KS_eacute,	KS_2,	KS_at,
    KC(32),	KS_quotedbl,	KS_3,	KS_numbersign,
    KC(33),	KS_apostrophe,	KS_4,
    KC(34),	KS_parenleft,	KS_5,
    KC(35),	KS_section,	KS_6,	KS_asciicircum,
    KC(36),	KS_egrave,	KS_7,
    KC(37),	KS_exclam,	KS_8,
    KC(38),	KS_ccedilla,	KS_9,	KS_braceleft,
    KC(39),	KS_agrave,	KS_0,	KS_braceright,
    KC(45),	KS_parenright,	KS_degree,
    KC(46),	KS_minus,	KS_underscore,
    KC(47),	KS_dead_circumflex,	KS_dead_diaeresis,	KS_bracketleft,
    KC(48),	KS_dollar,	KS_asterisk,	KS_bracketright,
    KC(50),	KS_mu,	KS_sterling,	KS_grave,
    KC(51),	KS_m,
    KC(52),	KS_ugrave,	KS_percent,	KS_acute,
    KC(53),	KS_twosuperior,	KS_threesuperior,
    KC(54),	KS_semicolon,	KS_period,
    KC(55),	KS_colon,	KS_slash,
    KC(56),	KS_equal,	KS_plus,	KS_asciitilde,
    KC(100),	KS_less,	KS_greater,	KS_backslash,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};


static const keysym_t ukbd_keydesc_us_dvorak[] = {
/*  pos      command		normal		shifted */
    KC(5),	KS_x,
    KC(6),	KS_j,
    KC(7),	KS_e,
    KC(8),	KS_period,	KS_greater,
    KC(9),	KS_u,
    KC(10),	KS_i,
    KC(11),	KS_d,
    KC(12),	KS_c,
    KC(13),	KS_h,
    KC(14),	KS_t,
    KC(15),	KS_n,
    KC(17),	KS_b,
    KC(18),	KS_r,
    KC(19),	KS_l,
    KC(20),	KS_apostrophe,	KS_quotedbl,
    KC(21),	KS_p,
    KC(22),	KS_o,
    KC(23),	KS_y,
    KC(24),	KS_g,
    KC(25),	KS_k,
    KC(26),	KS_comma,	KS_less,
    KC(27),	KS_q,
    KC(28),	KS_f,
    KC(29),	KS_semicolon,	KS_colon,
    KC(45),	KS_bracketleft,	KS_braceleft,
    KC(46),	KS_bracketright,	KS_braceright,
    KC(47),	KS_slash,	KS_question,
    KC(48),	KS_equal,	KS_plus,
    KC(51),	KS_s,
    KC(52),	KS_minus,	KS_underscore,
    KC(54),	KS_w,
    KC(55),	KS_v,
    KC(56),	KS_z,
};

static const keysym_t ukbd_keydesc_swapctrlcaps[] = {
/*  pos      command		normal		shifted */
    KC(57),	KS_Cmd1,	KS_Control_L,
    KC(224),	KS_Caps_Lock,
};

static const keysym_t ukbd_keydesc_iopener[] = {
/*  pos      command		normal		shifted */
    KC(58),	KS_Cmd_Debugger,	KS_Escape,
    KC(59),	KS_Cmd_Screen0,	KS_f1,
    KC(60),	KS_Cmd_Screen1,	KS_f2,
    KC(61),	KS_Cmd_Screen2,	KS_f3,
    KC(62),	KS_Cmd_Screen3,	KS_f4,
    KC(63),	KS_Cmd_Screen4,	KS_f5,
    KC(64),	KS_Cmd_Screen5,	KS_f6,
    KC(65),	KS_Cmd_Screen6,	KS_f7,
    KC(66),	KS_Cmd_Screen7,	KS_f8,
    KC(67),	KS_Cmd_Screen8,	KS_f9,
    KC(68),	KS_Cmd_Screen9,	KS_f10,
    KC(69),	KS_f11,
};

static const keysym_t ukbd_keydesc_ru[] = {
/*  pos      normal		shifted		altgr			shift-altgr */
    KC(4),	KS_a,	KS_A,	KS_Cyrillic_ef,	KS_Cyrillic_EF,
    KC(5),	KS_b,	KS_B,	KS_Cyrillic_i,	KS_Cyrillic_I,
    KC(6),	KS_c,	KS_C,	KS_Cyrillic_es,	KS_Cyrillic_ES,
    KC(7),	KS_d,	KS_D,	KS_Cyrillic_ve,	KS_Cyrillic_VE,
    KC(8),	KS_e,	KS_E,	KS_Cyrillic_u,	KS_Cyrillic_U,
    KC(9),	KS_f,	KS_F,	KS_Cyrillic_a,	KS_Cyrillic_A,
    KC(10),	KS_g,	KS_G,	KS_Cyrillic_pe,	KS_Cyrillic_PE,
    KC(11),	KS_h,	KS_H,	KS_Cyrillic_er,	KS_Cyrillic_ER,
    KC(12),	KS_i,	KS_I,	KS_Cyrillic_sha,	KS_Cyrillic_SHA,
    KC(13),	KS_j,	KS_J,	KS_Cyrillic_o,	KS_Cyrillic_O,
    KC(14),	KS_k,	KS_K,	KS_Cyrillic_el,	KS_Cyrillic_EL,
    KC(15),	KS_l,	KS_L,	KS_Cyrillic_de,	KS_Cyrillic_DE,
    KC(16),	KS_m,	KS_M,	KS_Cyrillic_ssighn,	KS_Cyrillic_SSIGHN,
    KC(17),	KS_n,	KS_N,	KS_Cyrillic_te,	KS_Cyrillic_TE,
    KC(18),	KS_o,	KS_O,	KS_Cyrillic_scha,	KS_Cyrillic_SCHA,
    KC(19),	KS_p,	KS_P,	KS_Cyrillic_ze,	KS_Cyrillic_ZE,
    KC(20),	KS_q,	KS_Q,	KS_Cyrillic_ishort,	KS_Cyrillic_ISHORT,
    KC(21),	KS_r,	KS_R,	KS_Cyrillic_ka,	KS_Cyrillic_KA,
    KC(22),	KS_s,	KS_S,	KS_Cyrillic_yeru,	KS_Cyrillic_YERU,
    KC(23),	KS_t,	KS_T,	KS_Cyrillic_ie,	KS_Cyrillic_IE,
    KC(24),	KS_u,	KS_U,	KS_Cyrillic_ge,	KS_Cyrillic_GE,
    KC(25),	KS_v,	KS_V,	KS_Cyrillic_em,	KS_Cyrillic_EM,
    KC(26),	KS_w,	KS_W,	KS_Cyrillic_tse,	KS_Cyrillic_TSE,
    KC(27),	KS_x,	KS_X,	KS_Cyrillic_che,	KS_Cyrillic_CHE,
    KC(28),	KS_y,	KS_Y,	KS_Cyrillic_en,	KS_Cyrillic_EN,
    KC(29),	KS_z,	KS_Z,	KS_Cyrillic_ya,	KS_Cyrillic_YA,
    KC(35),	KS_6,	KS_asciicircum,	KS_6,	KS_comma,
    KC(36),	KS_7,	KS_ampersand,	KS_7,	KS_period,
    KC(47),	KS_bracketleft,	KS_braceleft,	KS_Cyrillic_ha,	KS_Cyrillic_HA,
    KC(48),	KS_bracketright,	KS_braceright,	KS_Cyrillic_hsighn,	KS_Cyrillic_HSIGHN,
    KC(51),	KS_semicolon,	KS_colon,	KS_Cyrillic_zhe,	KS_Cyrillic_ZHE,
    KC(52),	KS_apostrophe,	KS_quotedbl,	KS_Cyrillic_e,	KS_Cyrillic_E,
    KC(54),	KS_comma,	KS_less,	KS_Cyrillic_be,	KS_Cyrillic_BE,
    KC(55),	KS_period,	KS_greater,	KS_Cyrillic_yu,	KS_Cyrillic_YU,
    KC(56),	KS_slash,	KS_question,	KS_Cyrillic_yo,	KS_Cyrillic_YO,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_ua[] = {
/*  pos      normal		shifted		altgr			shift-altgr */
    KC(4),	KS_a,	KS_A,	KS_Cyrillic_ef,	KS_Cyrillic_EF,
    KC(5),	KS_b,	KS_B,	KS_Cyrillic_i,	KS_Cyrillic_I,
    KC(6),	KS_c,	KS_C,	KS_Cyrillic_es,	KS_Cyrillic_ES,
    KC(7),	KS_d,	KS_D,	KS_Cyrillic_ve,	KS_Cyrillic_VE,
    KC(8),	KS_e,	KS_E,	KS_Cyrillic_u,	KS_Cyrillic_U,
    KC(9),	KS_f,	KS_F,	KS_Cyrillic_a,	KS_Cyrillic_A,
    KC(10),	KS_g,	KS_G,	KS_Cyrillic_pe,	KS_Cyrillic_PE,
    KC(11),	KS_h,	KS_H,	KS_Cyrillic_er,	KS_Cyrillic_ER,
    KC(12),	KS_i,	KS_I,	KS_Cyrillic_sha,	KS_Cyrillic_SHA,
    KC(13),	KS_j,	KS_J,	KS_Cyrillic_o,	KS_Cyrillic_O,
    KC(14),	KS_k,	KS_K,	KS_Cyrillic_el,	KS_Cyrillic_EL,
    KC(15),	KS_l,	KS_L,	KS_Cyrillic_de,	KS_Cyrillic_DE,
    KC(16),	KS_m,	KS_M,	KS_Cyrillic_ssighn,	KS_Cyrillic_SSIGHN,
    KC(17),	KS_n,	KS_N,	KS_Cyrillic_te,	KS_Cyrillic_TE,
    KC(18),	KS_o,	KS_O,	KS_Cyrillic_scha,	KS_Cyrillic_SCHA,
    KC(19),	KS_p,	KS_P,	KS_Cyrillic_ze,	KS_Cyrillic_ZE,
    KC(20),	KS_q,	KS_Q,	KS_Cyrillic_ishort,	KS_Cyrillic_ISHORT,
    KC(21),	KS_r,	KS_R,	KS_Cyrillic_ka,	KS_Cyrillic_KA,
    KC(22),	KS_s,	KS_S,	KS_Cyrillic_yeru,	KS_Cyrillic_YERU,
    KC(23),	KS_t,	KS_T,	KS_Cyrillic_ie,	KS_Cyrillic_IE,
    KC(24),	KS_u,	KS_U,	KS_Cyrillic_ge,	KS_Cyrillic_GE,
    KC(25),	KS_v,	KS_V,	KS_Cyrillic_em,	KS_Cyrillic_EM,
    KC(26),	KS_w,	KS_W,	KS_Cyrillic_tse,	KS_Cyrillic_TSE,
    KC(27),	KS_x,	KS_X,	KS_Cyrillic_che,	KS_Cyrillic_CHE,
    KC(28),	KS_y,	KS_Y,	KS_Cyrillic_en,	KS_Cyrillic_EN,
    KC(29),	KS_z,	KS_Z,	KS_Cyrillic_ya,	KS_Cyrillic_YA,
    KC(35),	KS_6,	KS_asciicircum,	KS_6,	KS_comma,
    KC(36),	KS_7,	KS_ampersand,	KS_7,	KS_period,
    KC(45),	KS_minus,	KS_underscore,	KS_Cyrillic_iukr,	KS_Cyrillic_IUKR,
    KC(46),	KS_equal,	KS_plus,	KS_Cyrillic_yeukr,	KS_Cyrillic_YEUKR,
    KC(47),	KS_bracketleft,	KS_braceleft,	KS_Cyrillic_ha,	KS_Cyrillic_HA,
    KC(48),	KS_bracketright,	KS_braceright,	KS_Cyrillic_hsighn,	KS_Cyrillic_HSIGHN,
    KC(50),	KS_backslash,	KS_bar,	KS_Cyrillic_yi,	KS_Cyrillic_YI,
    KC(51),	KS_semicolon,	KS_colon,	KS_Cyrillic_zhe,	KS_Cyrillic_ZHE,
    KC(52),	KS_apostrophe,	KS_quotedbl,	KS_Cyrillic_e,	KS_Cyrillic_E,
    KC(53),	KS_grave,	KS_asciitilde,	KS_Cyrillic_gheukr,	KS_Cyrillic_GHEUKR,
    KC(54),	KS_comma,	KS_less,	KS_Cyrillic_be,	KS_Cyrillic_BE,
    KC(55),	KS_period,	KS_greater,	KS_Cyrillic_yu,	KS_Cyrillic_YU,
    KC(56),	KS_slash,	KS_question,	KS_Cyrillic_yo,	KS_Cyrillic_YO,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_sg[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(8),	KS_e,	KS_E,	KS_currency,
    KC(28),	KS_z,
    KC(29),	KS_y,
    KC(30),	KS_1,	KS_plus,	KS_bar,
    KC(31),	KS_2,	KS_quotedbl,	KS_at,
    KC(32),	KS_3,	KS_asterisk,	KS_numbersign,
    KC(33),	KS_4,	KS_ccedilla,
    KC(35),	KS_6,	KS_ampersand,	KS_notsign,
    KC(36),	KS_7,	KS_slash,	KS_brokenbar,
    KC(37),	KS_8,	KS_parenleft,	KS_cent,
    KC(38),	KS_9,	KS_parenright,
    KC(39),	KS_0,	KS_equal,
    KC(45),	KS_apostrophe,	KS_question,	KS_dead_acute,
    KC(46),	KS_dead_circumflex,KS_dead_grave,	KS_dead_tilde,
    KC(47),	KS_udiaeresis,	KS_egrave,	KS_bracketleft,
    KC(48),	KS_dead_diaeresis,	KS_exclam,	KS_bracketright,
    KC(50),	KS_dollar,	KS_sterling,	KS_braceright,
    KC(51),	KS_odiaeresis,	KS_eacute,
    KC(52),	KS_adiaeresis,	KS_agrave,	KS_braceleft,
    KC(53),	KS_section,	KS_degree,	KS_dead_abovering,
    KC(54),	KS_comma,	KS_semicolon,
    KC(55),	KS_period,	KS_colon,
    KC(56),	KS_minus,	KS_underscore,
    KC(100),	KS_less,	KS_greater,	KS_backslash,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_sg_nodead[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(45),	KS_apostrophe,	KS_question,	KS_acute,
    KC(46),	KS_asciicircum,	KS_grave,	KS_asciitilde,
    KC(48),	KS_diaeresis,	KS_exclam,	KS_bracketright,
};

static const keysym_t ukbd_keydesc_sf[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(47),	KS_egrave,	KS_udiaeresis,	KS_bracketleft,
    KC(51),	KS_eacute,	KS_odiaeresis,
    KC(52),	KS_agrave,	KS_adiaeresis,	KS_braceleft,
};

static const keysym_t ukbd_keydesc_pt[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(31),	KS_2,	KS_quotedbl,	KS_at,
    KC(32),	KS_3,	KS_numbersign,	KS_sterling,
    KC(35),	KS_6,	KS_ampersand,
    KC(36),	KS_7,	KS_slash,	KS_braceleft,
    KC(37),	KS_8,	KS_parenleft,	KS_bracketleft,
    KC(38),	KS_9,	KS_parenright,	KS_bracketright,
    KC(39),	KS_0,	KS_equal,	KS_braceright,
    KC(45),	KS_apostrophe,	KS_question,
    KC(46),	KS_less,	KS_greater,
    KC(47),	KS_plus,	KS_asterisk,
    KC(48),	KS_dead_acute,	KS_dead_grave,
    KC(50),	KS_dead_tilde,	KS_dead_circumflex,
    KC(51),	KS_ccedilla,	KS_Ccedilla,
    KC(52),	KS_masculine,	KS_ordfeminine,
    KC(53),	KS_backslash,	KS_bar,
    KC(54),	KS_comma,	KS_semicolon,
    KC(55),	KS_period,	KS_colon,
    KC(56),	KS_minus,	KS_underscore,
    KC(100),	KS_less,	KS_greater,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_pt_apple[] = {
/*  pos		normal		shifted */
    KC(46),	KS_plus,	KS_asterisk,
    KC(47),	KS_masculine,	KS_ordfeminine,
    KC(50),	KS_backslash,	KS_bar,
    KC(52),	KS_dead_tilde,	KS_dead_circumflex
};

static const keysym_t ukbd_keydesc_la[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(20),	KS_q,	KS_Q,	KS_at,
    KC(30),	KS_1,	KS_exclam,
    KC(31),	KS_2,	KS_quotedbl,
    KC(32),	KS_3,	KS_numbersign,
    KC(35),	KS_6,	KS_ampersand,
    KC(36),	KS_7,	KS_slash,
    KC(37),	KS_8,	KS_parenleft,
    KC(38),	KS_9,	KS_parenright,
    KC(39),	KS_0,	KS_equal,
    KC(45),	KS_apostrophe,	KS_question,	KS_backslash,
    KC(46),	KS_questiondown,	KS_exclamdown,
    KC(47),	KS_dead_acute,	KS_dead_diaeresis,
    KC(48),	KS_plus,	KS_asterisk,	KS_asciitilde,
    KC(50),	KS_braceright,	KS_bracketright,KS_dead_grave,
    KC(51),	KS_ntilde,
    KC(52),	KS_braceleft,	KS_bracketleft,	KS_dead_circumflex,
    KC(53),	KS_bar,	KS_degree,	KS_notsign,
    KC(54),	KS_comma,	KS_semicolon,
    KC(55),	KS_period,	KS_colon,
    KC(56),	KS_minus,	KS_underscore,
    KC(100),	KS_less,	KS_greater,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_br[] = {
/*  pos      normal		shifted         altgr           shift-altgr */
    KC(30),	KS_1,	KS_exclam,	KS_onesuperior,
    KC(31),	KS_2,	KS_at,	KS_twosuperior,
    KC(32),	KS_3,	KS_numbersign,	KS_threesuperior,
    KC(33),	KS_4,	KS_dollar,	KS_sterling,
    KC(34),	KS_5,	KS_percent,	KS_cent,
    KC(35),	KS_6,	KS_dead_diaeresis,	KS_notsign,
    KC(46),	KS_equal,	KS_plus,	KS_section,
    KC(47),	KS_dead_acute,	KS_dead_grave,
    KC(48),	KS_bracketleft,	KS_braceleft,	KS_ordfeminine,
    KC(50),	KS_bracketright,	KS_braceright,	KS_masculine,
    KC(51),	KS_ccedilla,	KS_Ccedilla,
    KC(52),	KS_dead_tilde,	KS_dead_circumflex,
    KC(53),	KS_apostrophe,	KS_quotedbl,
    KC(56),	KS_semicolon,	KS_colon,
    KC(99),	KS_KP_Delete,	KS_KP_Decimal,
    KC(100),	KS_backslash,	KS_bar,
    KC(136),	KS_slash,	KS_question,	KS_degree,
};

static const keysym_t ukbd_keydesc_tr[] = {
/*  pos      normal		shifted         altgr           shift-altgr */
    KC(12),	KS_L5_idotless,	KS_I,
    KC(20),	KS_q,	KS_Q,	KS_at,
    KC(31),	KS_2,	KS_apostrophe,	KS_sterling,
    KC(32),	KS_3,	KS_asciicircum,	KS_numbersign,
    KC(33),	KS_4,	KS_plus,	KS_dollar,
    KC(34),	KS_5,	KS_percent,	KS_onehalf,
    KC(35),	KS_6,	KS_ampersand,
    KC(36),	KS_7,	KS_slash,	KS_braceleft,
    KC(37),	KS_8,	KS_parenleft,	KS_bracketleft,
    KC(38),	KS_9,	KS_parenright,	KS_bracketright,
    KC(39),	KS_0,	KS_equal,	KS_braceright,
    KC(45),	KS_asterisk,	KS_question,	KS_backslash,
    KC(46),	KS_minus,	KS_underscore,
    KC(47),	KS_L5_gbreve,	KS_L5_Gbreve,	KS_dead_diaeresis,
    KC(48),	KS_udiaeresis,	KS_Udiaeresis,	KS_asciitilde,
    KC(50),	KS_comma,	KS_semicolon,	KS_dead_grave,
    KC(51),	KS_L5_scedilla,	KS_L5_Scedilla,	KS_dead_acute,
    KC(52),	KS_i,	KS_L5_Idotabove,
    KC(53),	KS_quotedbl,	KS_eacute,
    KC(54),	KS_odiaeresis,	KS_Odiaeresis,
    KC(55),	KS_ccedilla,	KS_Ccedilla,
    KC(56),	KS_period,	KS_colon,
    KC(100),	KS_less,	KS_greater,	KS_bar,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_tr_nodead[] = {
/*  pos      normal		shifted         altgr           shift-altgr */
    KC(47),	KS_L5_gbreve,	KS_L5_Gbreve,
    KC(50),	KS_comma,	KS_semicolon,	KS_grave,
    KC(51),	KS_L5_scedilla,	KS_L5_Scedilla,	KS_apostrophe,
};

static const keysym_t ukbd_keydesc_pl[] = {
/*  pos      normal		shifted         altgr           shift-altgr */
    KC(4),	KS_a,	KS_A,	KS_L2_aogonek,	KS_L2_Aogonek,
    KC(6),	KS_c,	KS_C,	KS_L2_cacute,	KS_L2_Cacute,
    KC(8),	KS_e,	KS_E,	KS_L2_eogonek,	KS_L2_Eogonek,
    KC(15),	KS_l,	KS_L,	KS_L2_lstroke,	KS_L2_Lstroke,
    KC(17),	KS_n,	KS_N,	KS_L2_nacute,	KS_L2_Nacute,
    KC(18),	KS_o,	KS_O,	KS_oacute,	KS_Oacute,
    KC(22),	KS_s,	KS_S,	KS_L2_sacute,	KS_L2_Sacute,
    KC(27),	KS_x,	KS_X,	KS_L2_zacute,	KS_L2_Zacute,
    KC(29),	KS_z,	KS_Z,	KS_L2_zdotabove,KS_L2_Zdotabove,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_hu[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(5),	KS_b,	KS_B,	KS_braceleft,
    KC(6),	KS_c,	KS_C,	KS_ampersand,
    KC(9),	KS_f,	KS_F,	KS_bracketleft,
    KC(10),	KS_g,	KS_G,	KS_bracketright,
    KC(12),	KS_i,	KS_I,	KS_iacute,
    KC(13),	KS_j,	KS_J,	KS_iacute,
    KC(17),	KS_n,	KS_N,	KS_braceright,
    KC(20),	KS_q,	KS_Q,	KS_backslash,
    KC(25),	KS_v,	KS_V,	KS_at,
    KC(26),	KS_w,	KS_W,KS_bar,
    KC(27),	KS_x,	KS_X,	KS_numbersign,
    KC(28),	KS_z,	KS_Z,
    KC(29),	KS_y,	KS_Y,	KS_greater,
    KC(30),	KS_1,	KS_apostrophe,	KS_asciitilde,
    KC(31),	KS_2,	KS_quotedbl,
    KC(32),	KS_3,	KS_plus,	KS_asciicircum,
    KC(33),	KS_4,	KS_exclam,
    KC(34),	KS_5,	KS_percent,
    KC(35),	KS_6,	KS_slash,
    KC(36),	KS_7,	KS_equal,KS_grave,
    KC(37),	KS_8,	KS_parenleft,
    KC(38),	KS_9,	KS_parenright,	KS_acute,
    KC(39),	KS_odiaeresis,	KS_Odiaeresis,
    KC(45),	KS_udiaeresis,	KS_Udiaeresis,
    KC(46),	KS_oacute,	KS_Oacute,
    KC(47),	KS_odoubleacute,	KS_Odoubleacute,	KS_division,
    KC(48),	KS_uacute,	KS_Uacute,	KS_multiply,
    KC(50),	KS_udoubleacute,	KS_Udoubleacute,	KS_currency,
    KC(51),	KS_eacute,	KS_Eacute,	KS_dollar,
    KC(52),	KS_aacute,	KS_Aacute,	KS_ssharp,
    KC(53),	KS_0,	KS_section,
    KC(54),	KS_comma,	KS_question,	KS_semicolon,
    KC(55),	KS_period,	KS_colon,
    KC(56),	KS_minus,	KS_underscore,	KS_asterisk,
    KC(100),	KS_iacute,	KS_Iacute,	KS_less,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_si[]=
{
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(5),	KS_b,	KS_B,	KS_braceleft,
    KC(9),	KS_f,	KS_F,	KS_bracketleft,
    KC(10),	KS_g,	KS_G,	KS_bracketright,
    KC(14),	KS_k,	KS_K,	KS_L2_lstroke,
    KC(15),	KS_l,	KS_L,	KS_L2_Lstroke,
    KC(16),	KS_m,	KS_M,	KS_section,
    KC(17),	KS_n,	KS_N,	KS_braceright,
    KC(20),	KS_q,	KS_Q,	KS_backslash,
    KC(25),	KS_v,	KS_V,	KS_at,
    KC(26),	KS_w,	KS_W,	KS_bar,
    KC(28),	KS_z,	KS_Z,
    KC(29),	KS_y,	KS_Y,
    KC(30),	KS_1,	KS_exclam,	KS_asciitilde,
    KC(31),	KS_2,	KS_quotedbl,	KS_L2_caron,
    KC(32),	KS_3,	KS_numbersign,	KS_asciicircum,
    KC(33),	KS_4,	KS_dollar,	KS_L2_breve,
    KC(34),	KS_5,	KS_percent,	KS_degree,
    KC(35),	KS_6,	KS_ampersand,	KS_L2_ogonek,
    KC(36),	KS_7,	KS_slash,	KS_grave,
    KC(37),	KS_8,	KS_parenleft,	KS_L2_dotabove,
    KC(38),	KS_9,	KS_parenright,	KS_acute,
    KC(39),	KS_0,	KS_equal,	KS_L2_dblacute,
    KC(45),	KS_apostrophe,	KS_question,	KS_diaeresis,
    KC(46),	KS_plus,	KS_asterisk,	KS_cedilla,
    KC(47),	KS_L2_scaron,	KS_L2_Scaron,	KS_division,
    KC(48),	KS_L2_dstroke,	KS_L2_Dstroke,	KS_multiply,
    KC(50),	KS_L2_zcaron,	KS_L2_Zcaron,	KS_currency,
    KC(51),	KS_L2_ccaron,	KS_L2_Ccaron,
    KC(52),	KS_L2_cacute,	KS_L2_Cacute,	KS_ssharp,
    KC(53),	KS_cedilla,	KS_diaeresis,
    KC(54),	KS_comma,	KS_semicolon,
    KC(55),	KS_period,	KS_colon,
    KC(56),	KS_minus,	KS_underscore,
    KC(100),	KS_less,	KS_greater,
    KC(230),	KS_Mode_switch,	KS_Multi_key,
};

static const keysym_t ukbd_keydesc_cf[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(16),	KS_m,	KS_M,	KS_mu,
    KC(18),	KS_o,	KS_O,	KS_section,
    KC(19),	KS_p,	KS_P,	KS_paragraph,
    KC(30),	KS_1,	KS_exclam,	KS_plusminus,
    KC(31),	KS_2,	KS_quotedbl,	KS_at,
    KC(32),	KS_3,	KS_slash,	KS_sterling,
    KC(33),	KS_4,	KS_dollar,	KS_cent,
    KC(34),	KS_5,	KS_percent,	KS_diaeresis,
    KC(35),	KS_6,	KS_question,	KS_macron,
    KC(36),	KS_7,	KS_ampersand,	KS_brokenbar,
    KC(37),	KS_8,	KS_asterisk,	KS_twosuperior,
    KC(38),	KS_9,	KS_parenleft,	KS_threesuperior,
    KC(39),	KS_0,	KS_parenright,	KS_onequarter,
    KC(45),	KS_minus,	KS_underscore,	KS_onehalf,
    KC(46),	KS_equal,	KS_plus,	KS_threequarters,
    KC(47),	KS_dead_circumflex,KS_dead_circumflex,	KS_bracketleft,
    KC(48),	KS_dead_cedilla,KS_dead_diaeresis,	KS_bracketright,
    KC(50),	KS_less,	KS_greater,	KS_braceright,
    KC(51),	KS_semicolon,	KS_colon,	KS_asciitilde,
    KC(52),	KS_dead_grave,	KS_dead_grave,	KS_braceleft,
    KC(53),	KS_numbersign,	KS_bar,	KS_backslash,
    KC(54),	KS_comma,	KS_apostrophe,	KS_hyphen,
    KC(55),	KS_period,	KS_period,
    KC(56),	KS_eacute,	KS_Eacute,	KS_dead_acute,
    KC(100),	KS_guillemotleft,KS_guillemotright,	KS_degree,
    KC(230),	KS_Mode_switch,KS_Multi_key,
};

static const keysym_t ukbd_keydesc_cf_nodead[] = {
/*  pos      normal		shifted		altgr		shift-altgr */
    KC(47),	KS_asciicircum,KS_asciicircum,	KS_bracketleft,
    KC(48),	KS_cedilla,	KS_diaeresis,	KS_bracketright,
    KC(52),	KS_grave,	KS_grave,	KS_braceleft,
    KC(56),	KS_eacute,	KS_Eacute,	KS_acute,
};

#endif	/* SMALL_KERNEL */

#define KBD_MAP(name, base, map) \
			{ name, base, sizeof(map)/sizeof(keysym_t), map }

const struct wscons_keydesc ukbd_keydesctab[] = {
	KBD_MAP(KB_US,			0,	ukbd_keydesc_us),
#if !defined(SMALL_KERNEL) || !defined(__alpha__)
	KBD_MAP(KB_DE,			KB_US,	ukbd_keydesc_de),
	KBD_MAP(KB_DE | KB_NODEAD,	KB_DE,	ukbd_keydesc_de_nodead),
	KBD_MAP(KB_FR,			KB_US,	ukbd_keydesc_fr),
	KBD_MAP(KB_DK,			KB_US,	ukbd_keydesc_dk),
	KBD_MAP(KB_DK | KB_NODEAD,	KB_DK,	ukbd_keydesc_dk_nodead),
	KBD_MAP(KB_IT,			KB_US,	ukbd_keydesc_it),
	KBD_MAP(KB_UK,			KB_US,	ukbd_keydesc_uk),
	KBD_MAP(KB_JP,			KB_US,	ukbd_keydesc_jp),
	KBD_MAP(KB_SV,			KB_DK,	ukbd_keydesc_sv),
	KBD_MAP(KB_SV | KB_NODEAD,	KB_SV,	ukbd_keydesc_sv_nodead),
	KBD_MAP(KB_NO,			KB_DK,	ukbd_keydesc_no),
	KBD_MAP(KB_NO | KB_NODEAD,	KB_NO,	ukbd_keydesc_no_nodead),
	KBD_MAP(KB_US | KB_DVORAK,	KB_US,	ukbd_keydesc_us_dvorak),
	KBD_MAP(KB_US | KB_SWAPCTRLCAPS, KB_US,	ukbd_keydesc_swapctrlcaps),
	KBD_MAP(KB_US | KB_IOPENER,	KB_US,	ukbd_keydesc_iopener),
	KBD_MAP(KB_JP | KB_SWAPCTRLCAPS, KB_JP,	ukbd_keydesc_swapctrlcaps),
	KBD_MAP(KB_FR | KB_SWAPCTRLCAPS, KB_FR,	ukbd_keydesc_swapctrlcaps),
	KBD_MAP(KB_BE | KB_SWAPCTRLCAPS, KB_BE,	ukbd_keydesc_swapctrlcaps),
	KBD_MAP(KB_US | KB_DVORAK | KB_SWAPCTRLCAPS,	KB_US | KB_DVORAK,
		ukbd_keydesc_swapctrlcaps),
	KBD_MAP(KB_US | KB_IOPENER | KB_SWAPCTRLCAPS,	KB_US | KB_IOPENER,
		ukbd_keydesc_swapctrlcaps),
	KBD_MAP(KB_ES,			KB_US,	ukbd_keydesc_es),
	KBD_MAP(KB_BE,			KB_US,	ukbd_keydesc_be),
	KBD_MAP(KB_RU,			KB_US,	ukbd_keydesc_ru),
	KBD_MAP(KB_UA,			KB_US,	ukbd_keydesc_ua),
	KBD_MAP(KB_SG,			KB_US,	ukbd_keydesc_sg),
	KBD_MAP(KB_SG | KB_NODEAD,	KB_SG,	ukbd_keydesc_sg_nodead),
	KBD_MAP(KB_SF,			KB_SG,	ukbd_keydesc_sf),
	KBD_MAP(KB_SF | KB_NODEAD,	KB_SF,	ukbd_keydesc_sg_nodead),
	KBD_MAP(KB_PT,			KB_US,	ukbd_keydesc_pt),
	KBD_MAP(KB_PT | KB_APPLE,	KB_PT,	ukbd_keydesc_pt_apple),
	KBD_MAP(KB_LT,			KB_US,	ukbd_keydesc_lt),
	KBD_MAP(KB_LA,			KB_US,	ukbd_keydesc_la),
	KBD_MAP(KB_BR,			KB_US,	ukbd_keydesc_br),
	KBD_MAP(KB_TR,			KB_US,	ukbd_keydesc_tr),
	KBD_MAP(KB_TR | KB_NODEAD,	KB_TR,	ukbd_keydesc_tr_nodead),
	KBD_MAP(KB_PL,			KB_US,	ukbd_keydesc_pl),
	KBD_MAP(KB_HU,			KB_US,	ukbd_keydesc_hu),
	KBD_MAP(KB_SI,			KB_US,	ukbd_keydesc_si),
	KBD_MAP(KB_CF,			KB_US, 	ukbd_keydesc_cf),
	KBD_MAP(KB_CF | KB_NODEAD,	KB_CF,	ukbd_keydesc_cf_nodead),
#endif	/* SMALL_KERNEL */
	{0, 0, 0, 0}
};

#undef KBD_MAP
#undef KC
