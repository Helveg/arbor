.. _pyinterconnectivity:

Interconnectivity
#################

.. currentmodule:: arbor

.. class:: connection

    Describes a connection between two cells, defined by source and destination end points (that is pre-synaptic and post-synaptic respectively),
    a connection weight and a delay time.

    The :attr:`dest` does not include the gid of a cell, this is because a :class:`arbor.connection` is bound to the destination cell which means that the gid
    is implicitly known.

    .. function:: connection(source, destination, weight, delay)

        Construct a connection between the :attr:`source` and the :attr:`dest` with a :attr:`weight` and :attr:`delay`.

    .. attribute:: source

        The source end point of the connection (type: :class:`arbor.cell_member`, which can be initialized with a (gid, index) tuple).

    .. attribute:: dest

        The destination end point of the connection (type: :class:`arbor.cell_member.index` representing the index of the destination on the cell).
        The gid of the cell is implicitly known.

    .. attribute:: weight

        The weight delivered to the target synapse.
        The weight is dimensionless, and its interpretation is specific to the type of the synapse target.
        For example, the expsyn synapse interprets it as a conductance with units μS (micro-Siemens).

    .. attribute:: delay

        The delay time of the connection [ms]. Must be positive.

    An example of a connection reads as follows:

    .. container:: example-code

        .. code-block:: python

            import arbor

            def connections_on(gid):
               # construct a connection from the 0th source index of cell 2 (2,0)
               # to the 1st target index of cell gid (gid,1) with weight 0.01 and delay of 10 ms.
               src  = arbor.cell_member(2,0)
               dest = 1 # gid of the destination is is determined by the argument to `connections_on`
               w    = 0.01
               d    = 10
               return [arbor.connection(src, dest, w, d)]

.. class:: gap_junction_connection

    Describes a gap junction between two gap junction sites. Gap junction sites are identified by :class:`arbor.cell_member`.

    The :attr:`local` site does not include the gid of a cell, this is because a :class:`arbor.gap_junction_connection` is bound to
    the destination cell which means that the gid is implicitly known.

    .. note::

       A bidirectional gap-junction between two cells ``c0`` and ``c1`` requires two
       :class:`gap_junction_connection` objects to be constructed: one where ``c0`` is the
       :attr:`local` site, and ``c1`` is the :attr:`peer` site; and another where ``c1`` is the
       :attr:`local` site, and ``c0`` is the :attr:`peer` site. If :attr:`ggap` is equal
       in both connections, a symmetric gap-junction is formed, other wise the gap-junction is asymmetric.

    .. function::gap_junction_connection(peer, local, ggap)

        Construct a gap junction connection between :attr:`peer` and :attr:`local` with conductance :attr:`ggap`.

    .. attribute:: peer

        The gap junction site: the remote half of the gap junction connection (type: :class:`arbor.cell_member`,
        which can be initialized with a (gid, index) tuple).

    .. attribute:: local

        The gap junction site: the local half of the gap junction connection (type: :class:`arbor.cell_member.index`, representing
        the index of the local site on the cell). The gid of the cell is implicitly known.

    .. attribute:: ggap

        The gap junction conductance [μS].

.. class:: spike_detector

    A spike detector, generates a spike when voltage crosses a threshold. Can be used as source endpoint for an :class:`arbor.connection`.

    .. attribute:: threshold

        Voltage threshold of spike detector [mV]

