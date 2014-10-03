#-------------------------------------------------
#
# Project created by QtCreator 2014-09-04T14:49:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PDEViewer
TEMPLATE = app

INCLUDEPATH += $$_PRO_FILE_PWD_/include

<<<<<<< HEAD
SOURCES += \
    src/ctrlcmd.cpp \
    src/ctrlgraph.cpp \
    src/ctrlgui.cpp \
    src/ctrlmenubar.cpp \
    src/ctrlsliders.cpp \
    src/guiview.cpp \
    src/initview.cpp \
    src/main.cpp \
    src/model.cpp \
    src/sliderbox.cpp \
    src/uiview.cpp \
    src/MglWrapper/MglWrapper.cpp

HEADERS  += \
    include/mgl2/abstract.h \
    include/mgl2/addon.h \
    include/mgl2/base.h \
    include/mgl2/base_cf.h \
    include/mgl2/canvas.h \
    include/mgl2/canvas_cf.h \
    include/mgl2/canvas_wnd.h \
    include/mgl2/config.h \
    include/mgl2/cont.h \
    include/mgl2/data.h \
    include/mgl2/data_cf.h \
    include/mgl2/datac.h \
    include/mgl2/datac_cf.h \
    include/mgl2/define.h \
    include/mgl2/dllexport.h \
    include/mgl2/eval.h \
    include/mgl2/evalc.h \
    include/mgl2/fit.h \
    include/mgl2/fltk.h \
    include/mgl2/font.h \
    include/mgl2/mgl.h \
    include/mgl2/mgl_cf.h \
    include/mgl2/mpi.h \
    include/mgl2/opengl.h \
    include/mgl2/other.h \
    include/mgl2/parser.h \
    include/mgl2/pde.h \
    include/mgl2/plot.h \
    include/mgl2/prim.h \
    include/mgl2/qmathgl.h \
    include/mgl2/qt.h \
    include/mgl2/surf.h \
    include/mgl2/thread.h \
    include/mgl2/type.h \
    include/mgl2/vect.h \
    include/mgl2/volume.h \
    include/mgl2/window.h \
    include/mgl2/wnd.h \
    include/MglWrapper/MglWrapper.h \
    include/ctrlcmd.h \
    include/ctrlgraph.h \
    include/ctrlgui.h \
    include/ctrlmenubar.h \
    include/ctrlsliders.h \
    include/guiview.h \
    include/initview.h \
    include/model.h \
    include/sliderbox.h \
    include/uiview.h \
    include/gsl/config.h \
    include/gsl/gsl_blas.h \
    include/gsl/gsl_blas_types.h \
    include/gsl/gsl_block.h \
    include/gsl/gsl_block_char.h \
    include/gsl/gsl_block_complex_double.h \
    include/gsl/gsl_block_complex_float.h \
    include/gsl/gsl_block_complex_long_double.h \
    include/gsl/gsl_block_double.h \
    include/gsl/gsl_block_float.h \
    include/gsl/gsl_block_int.h \
    include/gsl/gsl_block_long.h \
    include/gsl/gsl_block_long_double.h \
    include/gsl/gsl_block_short.h \
    include/gsl/gsl_block_uchar.h \
    include/gsl/gsl_block_uint.h \
    include/gsl/gsl_block_ulong.h \
    include/gsl/gsl_block_ushort.h \
    include/gsl/gsl_cblas.h \
    include/gsl/gsl_cdf.h \
    include/gsl/gsl_chebyshev.h \
    include/gsl/gsl_check_range.h \
    include/gsl/gsl_combination.h \
    include/gsl/gsl_complex.h \
    include/gsl/gsl_complex_math.h \
    include/gsl/gsl_const.h \
    include/gsl/gsl_const_cgs.h \
    include/gsl/gsl_const_cgsm.h \
    include/gsl/gsl_const_mks.h \
    include/gsl/gsl_const_mksa.h \
    include/gsl/gsl_const_num.h \
    include/gsl/gsl_deriv.h \
    include/gsl/gsl_dft_complex.h \
    include/gsl/gsl_dft_complex_float.h \
    include/gsl/gsl_dht.h \
    include/gsl/gsl_diff.h \
    include/gsl/gsl_eigen.h \
    include/gsl/gsl_errno.h \
    include/gsl/gsl_fft.h \
    include/gsl/gsl_fft_complex.h \
    include/gsl/gsl_fft_complex_float.h \
    include/gsl/gsl_fft_halfcomplex.h \
    include/gsl/gsl_fft_halfcomplex_float.h \
    include/gsl/gsl_fft_real.h \
    include/gsl/gsl_fft_real_float.h \
    include/gsl/gsl_fit.h \
    include/gsl/gsl_heapsort.h \
    include/gsl/gsl_histogram.h \
    include/gsl/gsl_histogram2d.h \
    include/gsl/gsl_ieee_utils.h \
    include/gsl/gsl_integration.h \
    include/gsl/gsl_interp.h \
    include/gsl/gsl_linalg.h \
    include/gsl/gsl_machine.h \
    include/gsl/gsl_math.h \
    include/gsl/gsl_matrix.h \
    include/gsl/gsl_matrix_char.h \
    include/gsl/gsl_matrix_complex_double.h \
    include/gsl/gsl_matrix_complex_float.h \
    include/gsl/gsl_matrix_complex_long_double.h \
    include/gsl/gsl_matrix_double.h \
    include/gsl/gsl_matrix_float.h \
    include/gsl/gsl_matrix_int.h \
    include/gsl/gsl_matrix_long.h \
    include/gsl/gsl_matrix_long_double.h \
    include/gsl/gsl_matrix_short.h \
    include/gsl/gsl_matrix_uchar.h \
    include/gsl/gsl_matrix_uint.h \
    include/gsl/gsl_matrix_ulong.h \
    include/gsl/gsl_matrix_ushort.h \
    include/gsl/gsl_message.h \
    include/gsl/gsl_min.h \
    include/gsl/gsl_mode.h \
    include/gsl/gsl_monte.h \
    include/gsl/gsl_monte_miser.h \
    include/gsl/gsl_monte_plain.h \
    include/gsl/gsl_monte_vegas.h \
    include/gsl/gsl_multifit.h \
    include/gsl/gsl_multifit_nlin.h \
    include/gsl/gsl_multimin.h \
    include/gsl/gsl_multiroots.h \
    include/gsl/gsl_nan.h \
    include/gsl/gsl_ntuple.h \
    include/gsl/gsl_odeiv.h \
    include/gsl/gsl_permutation.h \
    include/gsl/gsl_permute.h \
    include/gsl/gsl_permute_char.h \
    include/gsl/gsl_permute_complex_double.h \
    include/gsl/gsl_permute_complex_float.h \
    include/gsl/gsl_permute_complex_long_double.h \
    include/gsl/gsl_permute_double.h \
    include/gsl/gsl_permute_float.h \
    include/gsl/gsl_permute_int.h \
    include/gsl/gsl_permute_long.h \
    include/gsl/gsl_permute_long_double.h \
    include/gsl/gsl_permute_short.h \
    include/gsl/gsl_permute_uchar.h \
    include/gsl/gsl_permute_uint.h \
    include/gsl/gsl_permute_ulong.h \
    include/gsl/gsl_permute_ushort.h \
    include/gsl/gsl_permute_vector.h \
    include/gsl/gsl_permute_vector_char.h \
    include/gsl/gsl_permute_vector_complex_double.h \
    include/gsl/gsl_permute_vector_complex_float.h \
    include/gsl/gsl_permute_vector_complex_long_double.h \
    include/gsl/gsl_permute_vector_double.h \
    include/gsl/gsl_permute_vector_float.h \
    include/gsl/gsl_permute_vector_int.h \
    include/gsl/gsl_permute_vector_long.h \
    include/gsl/gsl_permute_vector_long_double.h \
    include/gsl/gsl_permute_vector_short.h \
    include/gsl/gsl_permute_vector_uchar.h \
    include/gsl/gsl_permute_vector_uint.h \
    include/gsl/gsl_permute_vector_ulong.h \
    include/gsl/gsl_permute_vector_ushort.h \
    include/gsl/gsl_poly.h \
    include/gsl/gsl_pow_int.h \
    include/gsl/gsl_precision.h \
    include/gsl/gsl_qrng.h \
    include/gsl/gsl_randist.h \
    include/gsl/gsl_rng.h \
    include/gsl/gsl_roots.h \
    include/gsl/gsl_sf.h \
    include/gsl/gsl_sf_airy.h \
    include/gsl/gsl_sf_bessel.h \
    include/gsl/gsl_sf_clausen.h \
    include/gsl/gsl_sf_coulomb.h \
    include/gsl/gsl_sf_coupling.h \
    include/gsl/gsl_sf_dawson.h \
    include/gsl/gsl_sf_debye.h \
    include/gsl/gsl_sf_dilog.h \
    include/gsl/gsl_sf_elementary.h \
    include/gsl/gsl_sf_ellint.h \
    include/gsl/gsl_sf_elljac.h \
    include/gsl/gsl_sf_erf.h \
    include/gsl/gsl_sf_exp.h \
    include/gsl/gsl_sf_expint.h \
    include/gsl/gsl_sf_fermi_dirac.h \
    include/gsl/gsl_sf_gamma.h \
    include/gsl/gsl_sf_gegenbauer.h \
    include/gsl/gsl_sf_hyperg.h \
    include/gsl/gsl_sf_laguerre.h \
    include/gsl/gsl_sf_lambert.h \
    include/gsl/gsl_sf_legendre.h \
    include/gsl/gsl_sf_log.h \
    include/gsl/gsl_sf_pow_int.h \
    include/gsl/gsl_sf_psi.h \
    include/gsl/gsl_sf_result.h \
    include/gsl/gsl_sf_synchrotron.h \
    include/gsl/gsl_sf_transport.h \
    include/gsl/gsl_sf_trig.h \
    include/gsl/gsl_sf_zeta.h \
    include/gsl/gsl_siman.h \
    include/gsl/gsl_sort.h \
    include/gsl/gsl_sort_char.h \
    include/gsl/gsl_sort_double.h \
    include/gsl/gsl_sort_float.h \
    include/gsl/gsl_sort_int.h \
    include/gsl/gsl_sort_long.h \
    include/gsl/gsl_sort_long_double.h \
    include/gsl/gsl_sort_short.h \
    include/gsl/gsl_sort_uchar.h \
    include/gsl/gsl_sort_uint.h \
    include/gsl/gsl_sort_ulong.h \
    include/gsl/gsl_sort_ushort.h \
    include/gsl/gsl_sort_vector.h \
    include/gsl/gsl_sort_vector_char.h \
    include/gsl/gsl_sort_vector_double.h \
    include/gsl/gsl_sort_vector_float.h \
    include/gsl/gsl_sort_vector_int.h \
    include/gsl/gsl_sort_vector_long.h \
    include/gsl/gsl_sort_vector_long_double.h \
    include/gsl/gsl_sort_vector_short.h \
    include/gsl/gsl_sort_vector_uchar.h \
    include/gsl/gsl_sort_vector_uint.h \
    include/gsl/gsl_sort_vector_ulong.h \
    include/gsl/gsl_sort_vector_ushort.h \
    include/gsl/gsl_specfunc.h \
    include/gsl/gsl_spline.h \
    include/gsl/gsl_statistics.h \
    include/gsl/gsl_statistics_char.h \
    include/gsl/gsl_statistics_double.h \
    include/gsl/gsl_statistics_float.h \
    include/gsl/gsl_statistics_int.h \
    include/gsl/gsl_statistics_long.h \
    include/gsl/gsl_statistics_long_double.h \
    include/gsl/gsl_statistics_short.h \
    include/gsl/gsl_statistics_uchar.h \
    include/gsl/gsl_statistics_uint.h \
    include/gsl/gsl_statistics_ulong.h \
    include/gsl/gsl_statistics_ushort.h \
    include/gsl/gsl_sum.h \
    include/gsl/gsl_sys.h \
    include/gsl/gsl_test.h \
    include/gsl/gsl_types.h \
    include/gsl/gsl_vector.h \
    include/gsl/gsl_vector_char.h \
    include/gsl/gsl_vector_complex.h \
    include/gsl/gsl_vector_complex_double.h \
    include/gsl/gsl_vector_complex_float.h \
    include/gsl/gsl_vector_complex_long_double.h \
    include/gsl/gsl_vector_double.h \
    include/gsl/gsl_vector_float.h \
    include/gsl/gsl_vector_int.h \
    include/gsl/gsl_vector_long.h \
    include/gsl/gsl_vector_long_double.h \
    include/gsl/gsl_vector_short.h \
    include/gsl/gsl_vector_uchar.h \
    include/gsl/gsl_vector_uint.h \
    include/gsl/gsl_vector_ulong.h \
    include/gsl/gsl_vector_ushort.h \
    include/gsl/gsl_version.h \
    include/gsl/gsl_wavelet.h \
    include/gsl/gsl_wavelet2d.h \
=======
SOURCES += main.cpp\
        \ #uiview.cpp \
        model.cpp \
        guiview.cpp \
        sliderbox.cpp \
        ctrlgui.cpp \
        ctrlsliders.cpp \
    ctrlmenubar.cpp \
    ctrlcmd.cpp \
    ctrlgraph.cpp

HEADERS  += \#uiview.h \
        model.h \
        guiview.h \
        sliderbox.h \
        ctrlgui.h \
        ctrlsliders.h \
    ctrlmenubar.h \
    ctrlcmd.h \
    ctrlgraph.h

#FORMS    += uiview.ui
>>>>>>> parent of 79f3b53... Initial load dialog added

OTHER_FILES += \
        netlogogui.txt \
        temp.txt
