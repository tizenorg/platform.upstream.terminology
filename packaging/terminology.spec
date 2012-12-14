Name:           terminilogy
Version:        0.1
Release:        1
License:        BSD 2-clause
Summary:        Terminal Program
Url:            http://www.enlightenment.org/
Group:          Graphics/X11
Source0:        %{name}-%{version}.tar.bz2
%description
Terminilogy Terminal program.
%prep
%setup -q -n %{name}-%{version}


%build
%autogen
%configure 
make %{?_smp_mflags}

%install
%make_install

%files
%defattr(-,root,root,-)
%license COPYING
