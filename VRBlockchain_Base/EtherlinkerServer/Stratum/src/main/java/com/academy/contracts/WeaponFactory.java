package com.academy.contracts;

import io.reactivex.Flowable;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.Callable;
import org.web3j.abi.EventEncoder;
import org.web3j.abi.TypeReference;
import org.web3j.abi.datatypes.Address;
import org.web3j.abi.datatypes.DynamicArray;
import org.web3j.abi.datatypes.Event;
import org.web3j.abi.datatypes.Function;
import org.web3j.abi.datatypes.Type;
import org.web3j.abi.datatypes.Utf8String;
import org.web3j.abi.datatypes.generated.Uint16;
import org.web3j.abi.datatypes.generated.Uint256;
import org.web3j.abi.datatypes.generated.Uint32;
import org.web3j.abi.datatypes.generated.Uint8;
import org.web3j.crypto.Credentials;
import org.web3j.protocol.Web3j;
import org.web3j.protocol.core.DefaultBlockParameter;
import org.web3j.protocol.core.RemoteCall;
import org.web3j.protocol.core.methods.request.EthFilter;
import org.web3j.protocol.core.methods.response.Log;
import org.web3j.protocol.core.methods.response.TransactionReceipt;
import org.web3j.tuples.generated.Tuple7;
import org.web3j.tx.Contract;
import org.web3j.tx.TransactionManager;
import org.web3j.tx.gas.ContractGasProvider;

/**
 * <p>Auto generated code.
 * <p><strong>Do not modify!</strong>
 * <p>Please use the <a href="https://docs.web3j.io/command_line.html">web3j command line tools</a>,
 * or the org.web3j.codegen.SolidityFunctionWrapperGenerator in the 
 * <a href="https://github.com/web3j/web3j/tree/master/codegen">codegen module</a> to update.
 *
 * <p>Generated with web3j version 4.1.0.
 */
public class WeaponFactory extends Contract {
    private static final String BINARY = "60806040526010600055600060015534801561001a57600080fd5b50610f9e8061002a6000396000f3006080604052600436106100cf5763ffffffff7c01000000000000000000000000000000000000000000000000000000006000350416630187fcf381146100d457806301c6adc3146101455780630ce90ec21461016b5780631e3b38221461018357806325859a1a146101b75780633835054114610227578063555e73c81461023f5780636b2f60c81461031157806370a08231146103265780638c2f661e146103475780639e41b73f14610365578063b0ed0dc71461037d578063bd8256d2146103a5578063c39cbef1146103bd575b600080fd5b3480156100e057600080fd5b506100f5600160a060020a03600435166103e1565b60408051602080825283518183015283519192839290830191858101910280838360005b83811015610131578181015183820152602001610119565b505050509050019250505060405180910390f35b34801561015157600080fd5b50610169600160a060020a036004351660243561049f565b005b34801561017757600080fd5b506101696004356104d1565b34801561018f57600080fd5b5061019b6004356105a5565b60408051600160a060020a039092168252519081900360200190f35b3480156101c357600080fd5b506040805160206004803580820135601f81018490048402850184019095528484526102159436949293602493928401919081908401838280828437509497505050923560ff1693506105c092505050565b60408051918252519081900360200190f35b34801561023357600080fd5b5061019b60043561081e565b34801561024b57600080fd5b50610257600435610839565b6040805160ff881660208083019190915263ffffffff8089169383019390935291861660608201526080810185905261ffff80851660a0830152831660c082015260e08082528951908201528851909182916101008301918b019080838360005b838110156102d05781810151838201526020016102b8565b50505050905090810190601f1680156102fd5780820380516001836020036101000a031916815260200191505b509850505050505050505060405180910390f35b34801561031d57600080fd5b50610215610929565b34801561033257600080fd5b50610215600160a060020a0360043516610930565b34801561035357600080fd5b5061016960043560ff6024351661094b565b34801561037157600080fd5b506102576004356109ed565b34801561038957600080fd5b50610169602460048035828101929101359060ff903516610b57565b3480156103b157600080fd5b50610169600435610bb2565b3480156103c957600080fd5b50610169600480359060248035908101910135610c11565b6060806000806004600086600160a060020a0316600160a060020a0316815260200190815260200160002054604051908082528060200260200182016040528015610436578160200160208202803883390190505b50925060009150600090505b60025481101561049657600081815260036020526040902054600160a060020a038681169116141561048e5780838381518110151561047d57fe5b602090810290910101526001909101905b600101610442565b50909392505050565b600081815260036020526040902054600160a060020a031633146104c257600080fd5b6104cd338383610ca7565b5050565b61050e60016002838154811015156104e557fe5b600091825260209091206001600490920201015463ffffffff61010090910481169190610d7f16565b600280548390811061051c57fe5b906000526020600020906004020160010160016101000a81548163ffffffff021916908363ffffffff16021790555061057f600a60028381548110151561055f57fe5b906000526020600020906004020160020154610d9e90919063ffffffff16565b600280548390811061058d57fe5b90600052602060002090600402016002018190555050565b600360205260009081526040902054600160a060020a031681565b6040805160e08101825283815260ff831660208083019190915260019282018390524263ffffffff16606083015260146080830152600060a0830181905260c0830181905260028054808601808355918352845180519396879690959394909360049093027f405787fa12a823e0f2b7631cc41b3ba8828b3321ca811111fa75cd3aa3bb5ace0192610656928492910190610e30565b5060208281015160018381018054604080880151606089015160ff1990931660ff9096169590951764ffffffff00191661010063ffffffff968716021768ffffffff000000000019166501000000000092861692909202919091179091556080860151600286015560a08601516003958601805460c09098015161ffff1990981661ffff9283161763ffff000019166201000092909816919091029690961790955595909403600081815292825283832080543373ffffffffffffffffffffffffffffffffffffffff1990911681179091558352600490915291902054909350610742929091610d9e16565b6004600033600160a060020a0316600160a060020a03168152602001908152602001600020819055507f9d26e4755409d8cdc484d7a47f131ce8ef4e26c993833d9e0b58fa7a930fdb6d81858560405180848152602001806020018360ff168152602001828103825284818151815260200191508051906020019080838360005b838110156107db5781810151838201526020016107c3565b50505050905090810190601f1680156108085780820380516001836020036101000a031916815260200191505b5094505050505060405180910390a19392505050565b600090815260036020526040902054600160a060020a031690565b600280548290811061084757fe5b60009182526020918290206004919091020180546040805160026001841615610100026000190190931692909204601f8101859004850283018501909152808252919350918391908301828280156108e05780601f106108b5576101008083540402835291602001916108e0565b820191906000526020600020905b8154815290600101906020018083116108c357829003601f168201915b50505060018401546002850154600390950154939460ff82169463ffffffff6101008404811695506501000000000090930490921692509061ffff808216916201000090041687565b6001545b90565b600160a060020a031660009081526004602052604090205490565b6002828160028281548110151561095e57fe5b6000918252602090912060049091020160010154610100900463ffffffff16101561098857600080fd5b6000848152600360205260409020548490600160a060020a031633146109ad57600080fd5b836002868154811015156109bd57fe5b906000526020600020906004020160010160006101000a81548160ff021916908360ff1602179055505050505050565b6060600080600080600080610a00610eae565b600280548a908110610a0e57fe5b6000918252602091829020604080516004939093029091018054600260018216156101009081026000190190921604601f81018690049095028401810190925260e0830184815292939092849290918491840182828015610ab05780601f10610a8557610100808354040283529160200191610ab0565b820191906000526020600020905b815481529060010190602001808311610a9357829003601f168201915b5050509183525050600182015460ff811660208084019190915263ffffffff610100830481166040808601919091526501000000000090930416606080850191909152600285015460808086019190915260039095015461ffff80821660a080880191909152620100009092041660c095860152865192870151938701519187015195870151908701519690940151919f929e509c50929a50909850919650945092505050565b3360009081526004602052604090205415610b7157600080fd5b610bac83838080601f016020809104026020016040519081016040528093929190818152602001838380828437508794506105c09350505050565b50505050565b600081815260036020526040902054600160a060020a03163314610bd557600080fd5b610bdf3382610dad565b604051819060009033907fddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef908390a450565b60018381600282815481101515610c2457fe5b6000918252602090912060049091020160010154610100900463ffffffff161015610c4e57600080fd5b6000858152600360205260409020548590600160a060020a03163314610c7357600080fd5b8484600288815481101515610c8457fe5b60009182526020909120610c9e9360049092020191610eea565b50505050505050565b600160a060020a038216600090815260046020526040902054610cd190600163ffffffff610d9e16565b600160a060020a038316600090815260046020526040808220929092553381522054610d0490600163ffffffff610e1e16565b3360009081526004602090815260408083209390935583825260039052818120805473ffffffffffffffffffffffffffffffffffffffff1916600160a060020a038681169182179092559251849392918716917fddf252ad1be2c89b69c2b068fc378daa952ba7f163c4a11628f55a4df523b3ef91a4505050565b600082820163ffffffff8085169082161015610d9757fe5b9392505050565b600082820183811015610d9757fe5b6000818152600360209081526040808320805473ffffffffffffffffffffffffffffffffffffffff19169055600160a060020a03851683526004909152902054610dfe90600163ffffffff610e1e16565b600160a060020a0390921660009081526004602052604090209190915550565b600082821115610e2a57fe5b50900390565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f10610e7157805160ff1916838001178555610e9e565b82800160010185558215610e9e579182015b82811115610e9e578251825591602001919060010190610e83565b50610eaa929150610f58565b5090565b6040805160e081018252606080825260006020830181905292820183905281018290526080810182905260a0810182905260c081019190915290565b828054600181600116156101000203166002900490600052602060002090601f016020900481019282601f10610f2b5782800160ff19823516178555610e9e565b82800160010185558215610e9e579182015b82811115610e9e578235825591602001919060010190610f3d565b61092d91905b80821115610eaa5760008155600101610f5e5600a165627a7a72305820275badbdb9bf69e9fe929d54e596b15b460b0298124f42302aca7d192bfdc7900029";

    public static final String FUNC_GETWEAPONBYOWNER = "getWeaponByOwner";

    public static final String FUNC_TRANSFERFROM = "transferFrom";

    public static final String FUNC_LEVELUP = "levelUp";

    public static final String FUNC_WEAPONTOOWNER = "WeaponToOwner";

    public static final String FUNC_CREATEWEAPON = "createWeapon";

    public static final String FUNC__OWNEROF = "_ownerOf";

    public static final String FUNC_WEAPONS = "weapons";

    public static final String FUNC_GETLEVELUPFEE = "getLevelUpFee";

    public static final String FUNC_BALANCEOF = "balanceOf";

    public static final String FUNC_CHANGECREDS = "changeCreds";

    public static final String FUNC_GETWEAPON = "getWeapon";

    public static final String FUNC__NEWPLAYERCREATE = "_newPlayerCreate";

    public static final String FUNC_BURNN = "burnn";

    public static final String FUNC_CHANGENAME = "changeName";

    public static final Event NEWWEAPON_EVENT = new Event("NewWeapon", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}, new TypeReference<Utf8String>() {}, new TypeReference<Uint256>() {}));
    ;

    public static final Event TRANSFER_EVENT = new Event("Transfer", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}, new TypeReference<Address>(true) {}, new TypeReference<Uint256>(true) {}));
    ;

    public static final Event APPROVAL_EVENT = new Event("Approval", 
            Arrays.<TypeReference<?>>asList(new TypeReference<Address>(true) {}, new TypeReference<Address>(true) {}, new TypeReference<Uint256>(true) {}));
    ;

    @Deprecated
    protected WeaponFactory(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    protected WeaponFactory(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, credentials, contractGasProvider);
    }

    @Deprecated
    protected WeaponFactory(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    protected WeaponFactory(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public RemoteCall<List> getWeaponByOwner(String _owner) {
        final Function function = new Function(FUNC_GETWEAPONBYOWNER, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_owner)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<DynamicArray<Uint256>>() {}));
        return new RemoteCall<List>(
                new Callable<List>() {
                    @Override
                    @SuppressWarnings("unchecked")
                    public List call() throws Exception {
                        List<Type> result = (List<Type>) executeCallSingleValueReturn(function, List.class);
                        return convertToNative(result);
                    }
                });
    }

    public RemoteCall<TransactionReceipt> transferFrom(String _to, BigInteger _tokenId) {
        final Function function = new Function(
                FUNC_TRANSFERFROM, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_to), 
                new org.web3j.abi.datatypes.generated.Uint256(_tokenId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> levelUp(BigInteger _weaponId) {
        final Function function = new Function(
                FUNC_LEVELUP, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_weaponId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<String> WeaponToOwner(BigInteger param0) {
        final Function function = new Function(FUNC_WEAPONTOOWNER, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(param0)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Address>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<TransactionReceipt> createWeapon(String _name, BigInteger _wepType) {
        final Function function = new Function(
                FUNC_CREATEWEAPON, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Utf8String(_name), 
                new org.web3j.abi.datatypes.generated.Uint8(_wepType)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<String> _ownerOf(BigInteger _tokenId) {
        final Function function = new Function(FUNC__OWNEROF, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_tokenId)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Address>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>> weapons(BigInteger param0) {
        final Function function = new Function(FUNC_WEAPONS, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(param0)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}, new TypeReference<Uint8>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint256>() {}, new TypeReference<Uint16>() {}, new TypeReference<Uint16>() {}));
        return new RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>(
                new Callable<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>() {
                    @Override
                    public Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger> call() throws Exception {
                        List<Type> results = executeCallMultipleValueReturn(function);
                        return new Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>(
                                (String) results.get(0).getValue(), 
                                (BigInteger) results.get(1).getValue(), 
                                (BigInteger) results.get(2).getValue(), 
                                (BigInteger) results.get(3).getValue(), 
                                (BigInteger) results.get(4).getValue(), 
                                (BigInteger) results.get(5).getValue(), 
                                (BigInteger) results.get(6).getValue());
                    }
                });
    }

    public RemoteCall<BigInteger> getLevelUpFee() {
        final Function function = new Function(FUNC_GETLEVELUPFEE, 
                Arrays.<Type>asList(), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<BigInteger> balanceOf(String _owner) {
        final Function function = new Function(FUNC_BALANCEOF, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Address(_owner)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Uint256>() {}));
        return executeRemoteCallSingleValueReturn(function, BigInteger.class);
    }

    public RemoteCall<TransactionReceipt> changeCreds(BigInteger _weaponId, BigInteger _newCreds) {
        final Function function = new Function(
                FUNC_CHANGECREDS, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_weaponId), 
                new org.web3j.abi.datatypes.generated.Uint8(_newCreds)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>> getWeapon(BigInteger _id) {
        final Function function = new Function(FUNC_GETWEAPON, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_id)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}, new TypeReference<Uint8>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint32>() {}, new TypeReference<Uint256>() {}, new TypeReference<Uint16>() {}, new TypeReference<Uint16>() {}));
        return new RemoteCall<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>(
                new Callable<Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>>() {
                    @Override
                    public Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger> call() throws Exception {
                        List<Type> results = executeCallMultipleValueReturn(function);
                        return new Tuple7<String, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger, BigInteger>(
                                (String) results.get(0).getValue(), 
                                (BigInteger) results.get(1).getValue(), 
                                (BigInteger) results.get(2).getValue(), 
                                (BigInteger) results.get(3).getValue(), 
                                (BigInteger) results.get(4).getValue(), 
                                (BigInteger) results.get(5).getValue(), 
                                (BigInteger) results.get(6).getValue());
                    }
                });
    }

    public RemoteCall<TransactionReceipt> _newPlayerCreate(String _name, BigInteger _wepType) {
        final Function function = new Function(
                FUNC__NEWPLAYERCREATE, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.Utf8String(_name), 
                new org.web3j.abi.datatypes.generated.Uint8(_wepType)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> burnn(BigInteger _tokenId) {
        final Function function = new Function(
                FUNC_BURNN, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_tokenId)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public RemoteCall<TransactionReceipt> changeName(BigInteger _weaponId, String _newName) {
        final Function function = new Function(
                FUNC_CHANGENAME, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(_weaponId), 
                new org.web3j.abi.datatypes.Utf8String(_newName)), 
                Collections.<TypeReference<?>>emptyList());
        return executeRemoteCallTransaction(function);
    }

    public List<NewWeaponEventResponse> getNewWeaponEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(NEWWEAPON_EVENT, transactionReceipt);
        ArrayList<NewWeaponEventResponse> responses = new ArrayList<NewWeaponEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            NewWeaponEventResponse typedResponse = new NewWeaponEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse.weaponId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
            typedResponse.name = (String) eventValues.getNonIndexedValues().get(1).getValue();
            typedResponse.wepType = (BigInteger) eventValues.getNonIndexedValues().get(2).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<NewWeaponEventResponse> newWeaponEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, NewWeaponEventResponse>() {
            @Override
            public NewWeaponEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(NEWWEAPON_EVENT, log);
                NewWeaponEventResponse typedResponse = new NewWeaponEventResponse();
                typedResponse.log = log;
                typedResponse.weaponId = (BigInteger) eventValues.getNonIndexedValues().get(0).getValue();
                typedResponse.name = (String) eventValues.getNonIndexedValues().get(1).getValue();
                typedResponse.wepType = (BigInteger) eventValues.getNonIndexedValues().get(2).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<NewWeaponEventResponse> newWeaponEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(NEWWEAPON_EVENT));
        return newWeaponEventFlowable(filter);
    }

    public List<TransferEventResponse> getTransferEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(TRANSFER_EVENT, transactionReceipt);
        ArrayList<TransferEventResponse> responses = new ArrayList<TransferEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            TransferEventResponse typedResponse = new TransferEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse._from = (String) eventValues.getIndexedValues().get(0).getValue();
            typedResponse._to = (String) eventValues.getIndexedValues().get(1).getValue();
            typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<TransferEventResponse> transferEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, TransferEventResponse>() {
            @Override
            public TransferEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(TRANSFER_EVENT, log);
                TransferEventResponse typedResponse = new TransferEventResponse();
                typedResponse.log = log;
                typedResponse._from = (String) eventValues.getIndexedValues().get(0).getValue();
                typedResponse._to = (String) eventValues.getIndexedValues().get(1).getValue();
                typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<TransferEventResponse> transferEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(TRANSFER_EVENT));
        return transferEventFlowable(filter);
    }

    public List<ApprovalEventResponse> getApprovalEvents(TransactionReceipt transactionReceipt) {
        List<Contract.EventValuesWithLog> valueList = extractEventParametersWithLog(APPROVAL_EVENT, transactionReceipt);
        ArrayList<ApprovalEventResponse> responses = new ArrayList<ApprovalEventResponse>(valueList.size());
        for (Contract.EventValuesWithLog eventValues : valueList) {
            ApprovalEventResponse typedResponse = new ApprovalEventResponse();
            typedResponse.log = eventValues.getLog();
            typedResponse._owner = (String) eventValues.getIndexedValues().get(0).getValue();
            typedResponse._approved = (String) eventValues.getIndexedValues().get(1).getValue();
            typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
            responses.add(typedResponse);
        }
        return responses;
    }

    public Flowable<ApprovalEventResponse> approvalEventFlowable(EthFilter filter) {
        return web3j.ethLogFlowable(filter).map(new io.reactivex.functions.Function<Log, ApprovalEventResponse>() {
            @Override
            public ApprovalEventResponse apply(Log log) {
                Contract.EventValuesWithLog eventValues = extractEventParametersWithLog(APPROVAL_EVENT, log);
                ApprovalEventResponse typedResponse = new ApprovalEventResponse();
                typedResponse.log = log;
                typedResponse._owner = (String) eventValues.getIndexedValues().get(0).getValue();
                typedResponse._approved = (String) eventValues.getIndexedValues().get(1).getValue();
                typedResponse._tokenId = (BigInteger) eventValues.getIndexedValues().get(2).getValue();
                return typedResponse;
            }
        });
    }

    public Flowable<ApprovalEventResponse> approvalEventFlowable(DefaultBlockParameter startBlock, DefaultBlockParameter endBlock) {
        EthFilter filter = new EthFilter(startBlock, endBlock, getContractAddress());
        filter.addSingleTopic(EventEncoder.encode(APPROVAL_EVENT));
        return approvalEventFlowable(filter);
    }

    @Deprecated
    public static WeaponFactory load(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return new WeaponFactory(contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    @Deprecated
    public static WeaponFactory load(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return new WeaponFactory(contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    public static WeaponFactory load(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return new WeaponFactory(contractAddress, web3j, credentials, contractGasProvider);
    }

    public static WeaponFactory load(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return new WeaponFactory(contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public static RemoteCall<WeaponFactory> deploy(Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(WeaponFactory.class, web3j, credentials, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<WeaponFactory> deploy(Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(WeaponFactory.class, web3j, credentials, gasPrice, gasLimit, BINARY, "");
    }

    public static RemoteCall<WeaponFactory> deploy(Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(WeaponFactory.class, web3j, transactionManager, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<WeaponFactory> deploy(Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(WeaponFactory.class, web3j, transactionManager, gasPrice, gasLimit, BINARY, "");
    }

    public static class NewWeaponEventResponse {
        public Log log;

        public BigInteger weaponId;

        public String name;

        public BigInteger wepType;
    }

    public static class TransferEventResponse {
        public Log log;

        public String _from;

        public String _to;

        public BigInteger _tokenId;
    }

    public static class ApprovalEventResponse {
        public Log log;

        public String _owner;

        public String _approved;

        public BigInteger _tokenId;
    }
}
