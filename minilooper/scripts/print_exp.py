#!/bin/env python

import math

def get_yield(fname):
    f = open(fname)
    lines = f.readlines()
    for line in lines:
        if "Bin1" in line:
            ls = line.strip()
            ls = ls.split()
            # print(ls)
            y = float(ls[19])+ float(ls[15])+ float(ls[11])+ float(ls[7])+ float(ls[3])
            e = math.sqrt(float(ls[21])**2+ float(ls[17])**2+ float(ls[13])**2+ float(ls[9])**2+ float(ls[5])**2)
            ny = float(ls[23])
            ne = float(ls[25])
            d = float(ls[31])
            break
    return float(y), float(e), float(ny), float(ne), float(d)

El_SR_y , El_SR_e  , El_SR_ny , El_SR_ne , El_SR_d  = get_yield("plots/Nominal/v2.4_SS/v1/Run2/SRYield/ElMbbOnSRA__Yield.txt")
Mu_SR_y , Mu_SR_e  , Mu_SR_ny , Mu_SR_ne , Mu_SR_d  = get_yield("plots/Nominal/v2.4_SS/v1/Run2/SRYield/MuMbbOnSRA__Yield.txt")
Tau_SR_y, Tau_SR_e , Tau_SR_ny, Tau_SR_ne, Tau_SR_d = get_yield("plots/Nominal/v2.4_SS/v1/Run2/SRYield/TauMbbOnSRA__Yield.txt")
Neg_SR_y, Neg_SR_e , Neg_SR_ny, Neg_SR_ne, Neg_SR_d = get_yield("plots/Nominal/v2.4_SS/v1/Run2/SRYield/NegMbbOnSRA__Yield.txt")
Lgt_SR_y, Lgt_SR_e , Lgt_SR_ny, Lgt_SR_ne, Lgt_SR_d = get_yield("plots/Nominal/v2.4_SS/v1/Run2/SRYield/LgtMbbOnSRA2__Yield.txt")

El_CR_y , El_CR_e  , El_CR_ny , El_CR_ne , El_CR_d  = get_yield("plots/Nominal/v2.4_SS/v1/Run2/AnchorYield/ElMbbOffCRA__Yield.txt")
Mu_CR_y , Mu_CR_e  , Mu_CR_ny , Mu_CR_ne , Mu_CR_d  = get_yield("plots/Nominal/v2.4_SS/v1/Run2/AnchorYield/MuMbbOffCRA__Yield.txt")
Tau_CR_y, Tau_CR_e , Tau_CR_ny, Tau_CR_ne, Tau_CR_d = get_yield("plots/Nominal/v2.4_SS/v1/Run2/AnchorYield/TauMbbOffCRA__Yield.txt")
Neg_CR_y, Neg_CR_e , Neg_CR_ny, Neg_CR_ne, Neg_CR_d = get_yield("plots/Nominal/v2.4_SS/v1/Run2/AnchorYield/NegMbbOffCRA__Yield.txt")
Lgt_CR_y, Lgt_CR_e , Lgt_CR_ny, Lgt_CR_ne, Lgt_CR_d = get_yield("plots/Nominal/v2.4_SS/v1/Run2/AnchorYield/LgtMbbOffCRA__Yield.txt")

def bd(ny, ne, d):
    if d == 0:
        return 0
    else:
        return (d - ny)

def bderr(ny, ne, d):
    if d == 0:
        return 0
    else:
        return math.sqrt(d + ne**2)

def alpha(y1, e1, y2, e2):
    if y1 == 0 or y2 == 0:
        return 0
    else:
        return y1 / y2

def alphaerr(y1, e1, y2, e2):
    if y1 == 0 or y2 == 0:
        return 0
    else:
        return math.sqrt((e1/y1)**2 + (e2/y2)**2) * (y1/y2)

def bdsr(alpha, alphaerr, asyst1, asyst2, bd, bderr):
    if alpha == 0 or bd == 0:
        return 0
    else:
        return alpha * bd

def bdsrerr(alpha, alphaerr, asyst1, asyst2, bd, bderr):
    if alpha == 0 or bd == 0:
        return 0
    else:
        return math.sqrt((alphaerr/alpha)**2 + (asyst1/alpha)**2+(asyst2/alpha)**2+ (bderr/bd)**2) * (alpha*bd)

El_alpha  = alpha(El_SR_y  , El_SR_e  , El_CR_y  , El_CR_e) 
Mu_alpha  = alpha(Mu_SR_y  , Mu_SR_e  , Mu_CR_y  , Mu_CR_e) 
Tau_alpha = alpha(Tau_SR_y , Tau_SR_e , Tau_CR_y , Tau_CR_e)
Neg_alpha = alpha(Neg_SR_y , Neg_SR_e , Neg_CR_y , Neg_CR_e)
Lgt_alpha = alpha(Lgt_SR_y , Lgt_SR_e , Lgt_CR_y , Lgt_CR_e)

El_alphaerr  = alphaerr(El_SR_y  , El_SR_e  , El_CR_y  , El_CR_e) 
Mu_alphaerr  = alphaerr(Mu_SR_y  , Mu_SR_e  , Mu_CR_y  , Mu_CR_e) 
Tau_alphaerr = alphaerr(Tau_SR_y , Tau_SR_e , Tau_CR_y , Tau_CR_e)
Neg_alphaerr = alphaerr(Neg_SR_y , Neg_SR_e , Neg_CR_y , Neg_CR_e)
Lgt_alphaerr = alphaerr(Lgt_SR_y , Lgt_SR_e , Lgt_CR_y , Lgt_CR_e)

El_bd  = bd(El_CR_ny  , El_CR_ne  , El_CR_d)
Mu_bd  = bd(Mu_CR_ny  , Mu_CR_ne  , Mu_CR_d)
Tau_bd = bd(Tau_CR_ny , Tau_CR_ne , Tau_CR_d)
Neg_bd = bd(Neg_CR_ny , Neg_CR_ne , Neg_CR_d)
Lgt_bd = bd(Lgt_CR_ny , Lgt_CR_ne , Lgt_CR_d)

El_bderr  = bderr(El_CR_ny  , El_CR_ne  , El_CR_d)
Mu_bderr  = bderr(Mu_CR_ny  , Mu_CR_ne  , Mu_CR_d)
Tau_bderr = bderr(Tau_CR_ny , Tau_CR_ne , Tau_CR_d)
Neg_bderr = bderr(Neg_CR_ny , Neg_CR_ne , Neg_CR_d)
Lgt_bderr = bderr(Lgt_CR_ny , Lgt_CR_ne , Lgt_CR_d)

El_bdsr  = bdsr(El_alpha  , El_alphaerr  , 0.25*El_alpha  , 0.25*El_alpha , El_bd  , El_bderr )
Mu_bdsr  = bdsr(Mu_alpha  , Mu_alphaerr  , 0.25*Mu_alpha  , 0.25*Mu_alpha , Mu_bd  , Mu_bderr )
Tau_bdsr = bdsr(Tau_alpha , Tau_alphaerr , 0.45*Tau_alpha , 0.45*Tau_alpha, Tau_bd , Tau_bderr)
Neg_bdsr = bdsr(Neg_alpha , Neg_alphaerr , 0.70*Neg_alpha , 0.70*Neg_alpha, Neg_bd , Neg_bderr)
Lgt_bdsr = bdsr(Lgt_alpha , Lgt_alphaerr , 0.25*Lgt_alpha , 0.25*Lgt_alpha, Lgt_bd , Lgt_bderr)

El_bdsrerr  = bdsrerr(El_alpha  , El_alphaerr  , 0.25*El_alpha  , 0.25*El_alpha , El_bd  , El_bderr )
Mu_bdsrerr  = bdsrerr(Mu_alpha  , Mu_alphaerr  , 0.25*Mu_alpha  , 0.25*Mu_alpha , Mu_bd  , Mu_bderr )
Tau_bdsrerr = bdsrerr(Tau_alpha , Tau_alphaerr , 0.45*Tau_alpha , 0.45*Tau_alpha, Tau_bd , Tau_bderr)
Neg_bdsrerr = bdsrerr(Neg_alpha , Neg_alphaerr , 0.70*Neg_alpha , 0.70*Neg_alpha, Neg_bd , Neg_bderr)
Lgt_bdsrerr = bdsrerr(Lgt_alpha , Lgt_alphaerr , 0.25*Lgt_alpha , 0.25*Lgt_alpha, Lgt_bd , Lgt_bderr)

El_bdsrfracerr  = El_bdsrerr  / El_bdsr   * 100.
Mu_bdsrfracerr  = Mu_bdsrerr  / Mu_bdsr   * 100.
Tau_bdsrfracerr = Tau_bdsrerr / Tau_bdsr  * 100.
Neg_bdsrfracerr = Neg_bdsrerr / Neg_bdsr  * 100.
Lgt_bdsrfracerr = Lgt_bdsrerr / Lgt_bdsr  * 100.

result = """
\\begin{{table}}[H]
\\centering
\\resizebox{{\\columnwidth}}{{!}}{{%
\\begin{{tabular}}{{@{{\\extracolsep{{4pt}}}}lccccc@{{}}}}
\\hline\\hline
  Channels                 & ($B^\\textrm{{SR}}_\\textrm{{MC}}$\\quad\\quad / & $B^\\textrm{{CR}}_\\textrm{{MC}}$ = & $\\alpha_\\textrm{{exp}}$(MC Stat. $\\oplus$ Modeling Syst. $\\oplus$ Composition Syst.))\\quad\\quad $\\times$      & $B^\\textrm{{CR}}_\\textrm{{data}}$  \\quad\\quad= & $B^\\textrm{{SR}}_\\textrm{{data}}$       \\\\
  \\hline
  $e^{{+}}l^{{+}}$         & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.3g} $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $\\mu^{{+}}l^{{+}}$      & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.3g} $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $\\tau^{{+}}l^{{+}}$     & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.3g} $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $(--)$                   & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.3g} $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $\\ell^{{+}}\\ell^{{+}}$ & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.3g} $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
\\hline\\hline
\\end{{tabular}}
}}
\\caption{{\\label{{tab:extrapolation}} Extrapolation factors}}
\\end{{table}}
""".format(
        El_SR_y  , El_SR_e  , El_CR_y  , El_CR_e  , El_alpha  , El_alphaerr  , 0.25*100 , 0.25*100 , El_bd  , El_bderr  , El_bdsr  , El_bdsrerr  ,El_bdsrfracerr, 
        Mu_SR_y  , Mu_SR_e  , Mu_CR_y  , Mu_CR_e  , Mu_alpha  , Mu_alphaerr  , 0.25*100 , 0.25*100 , Mu_bd  , Mu_bderr  , Mu_bdsr  , Mu_bdsrerr  ,Mu_bdsrfracerr, 
        Tau_SR_y , Tau_SR_e , Tau_CR_y , Tau_CR_e , Tau_alpha , Tau_alphaerr , 0.45*100 , 0.45*100 , Tau_bd , Tau_bderr , Tau_bdsr , Tau_bdsrerr ,Tau_bdsrfracerr, 
        Neg_SR_y , Neg_SR_e , Neg_CR_y , Neg_CR_e , Neg_alpha , Neg_alphaerr , 0.70*100 , 0.70*100 , Neg_bd , Neg_bderr , Neg_bdsr , Neg_bdsrerr ,Neg_bdsrfracerr, 
        Lgt_SR_y , Lgt_SR_e , Lgt_CR_y , Lgt_CR_e , Lgt_alpha , Lgt_alphaerr , 0.25*100 , 0.25*100 , Lgt_bd , Lgt_bderr , Lgt_bdsr , Lgt_bdsrerr ,Lgt_bdsrfracerr, 
        )


print(result)
