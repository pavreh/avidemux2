INCLUDE(vf_plugin)


SET(ADM_vf_Delta_SRCS ADM_vidDelta.cpp)

ADD_LIBRARY(ADM_vf_Delta SHARED ${ADM_vf_Delta_SRCS})

INIT_VIDEOFILTER_PLUGIN(ADM_vf_Delta)
INSTALL_VIDEOFILTER(ADM_vf_Delta)
