# -*- Mode: python; py-indent-offset: 4; indent-tabs-mode: nil; coding: utf-8; -*-

# def options(opt):
#     pass

# def configure(conf):
#     conf.check_nonfatal(header_name='stdint.h', define_name='HAVE_STDINT_H')

def build(bld):
    module = bld.create_ns3_module('qtcp', ['core','network','internet','point-to-point','applications','stats','csma','flow-monitor','point-to-point-layout'])
    module.source = [
        'model/qtcp.cc',
        'model/TerminalApplication.cc',
        'model/QTCPSimulator.cc',
        'model/QTCPCongestion.cc',
        'model/RLTrainer.cc',
        'helper/qtcp-helper.cc',
        ]

    module_test = bld.create_ns3_module_test_library('qtcp')
    module_test.source = [
        'test/qtcp-test-suite.cc',
        ]

    headers = bld(features='ns3header')
    headers.module = 'qtcp'
    headers.source = [
        'model/qtcp.h',
        'model/TerminalApplication.h',
        'model/QTCPSimulator.h',
        'model/QTCPCongestion.h',
        'model/RLTrainer.h',
        'helper/qtcp-helper.h',
        ]

    if bld.env.ENABLE_EXAMPLES:
        bld.recurse('examples')

    # bld.ns3_python_bindings()

